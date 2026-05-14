#include <Arduino.h>
#include <ESP32Servo.h>

#include "PIDController.h"

namespace {
constexpr uint8_t SERVO_1_PIN = 13;
constexpr uint8_t SERVO_2_PIN = 14;
constexpr uint8_t SERVO_3_PIN = 27;
constexpr uint8_t SERVO_4_PIN = 26;

constexpr float SETPOINT_ROLL_DEG = 0.0f;
constexpr float SETPOINT_PITCH_DEG = 0.0f;
constexpr float SERVO_NEUTRAL_DEG = 90.0f;
constexpr float SERVO_LIMIT_DEG = 20.0f;

#ifndef CONTROL_LOOP_HZ
constexpr uint32_t CONTROL_LOOP_HZ_VALUE = 500;
#else
constexpr uint32_t CONTROL_LOOP_HZ_VALUE = CONTROL_LOOP_HZ;
#endif

constexpr uint32_t CONTROL_LOOP_INTERVAL_US = 1000000UL / CONTROL_LOOP_HZ_VALUE;

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

PIDController rollPid(0.4f, 0.0f, 0.04f, SERVO_LIMIT_DEG);
PIDController pitchPid(0.4f, 0.0f, 0.04f, SERVO_LIMIT_DEG);

uint32_t previousLoopUs = 0;
uint32_t lastLoopDtUs = CONTROL_LOOP_INTERVAL_US;
uint32_t loopCount = 0;

float clampServo(float commandDeg) {
  const float low = SERVO_NEUTRAL_DEG - SERVO_LIMIT_DEG;
  const float high = SERVO_NEUTRAL_DEG + SERVO_LIMIT_DEG;
  return constrain(commandDeg, low, high);
}

float readRollDeg() {
  // TODO: Replace with estimator output from MPU-6050 accel/gyro fusion.
  return 0.0f;
}

float readPitchDeg() {
  // TODO: Replace with estimator output from MPU-6050 accel/gyro fusion.
  return 0.0f;
}

void writeFourFinMixer(float rollCorrectionDeg, float pitchCorrectionDeg) {
  const float servo1Command = clampServo(SERVO_NEUTRAL_DEG + pitchCorrectionDeg);
  const float servo2Command = clampServo(SERVO_NEUTRAL_DEG - pitchCorrectionDeg);
  const float servo3Command = clampServo(SERVO_NEUTRAL_DEG + rollCorrectionDeg);
  const float servo4Command = clampServo(SERVO_NEUTRAL_DEG - rollCorrectionDeg);

  servo1.write(servo1Command);
  servo2.write(servo2Command);
  servo3.write(servo3Command);
  servo4.write(servo4Command);
}

void printTiming(float rollDeg, float pitchDeg, float rollOutput, float pitchOutput) {
  Serial.print("loop_dt_us=");
  Serial.print(lastLoopDtUs);
  Serial.print(", roll_deg=");
  Serial.print(rollDeg, 3);
  Serial.print(", pitch_deg=");
  Serial.print(pitchDeg, 3);
  Serial.print(", pid_roll=");
  Serial.print(rollOutput, 3);
  Serial.print(", pid_pitch=");
  Serial.println(pitchOutput, 3);
}
} // namespace

void setup() {
  Serial.begin(115200);

  servo1.attach(SERVO_1_PIN);
  servo2.attach(SERVO_2_PIN);
  servo3.attach(SERVO_3_PIN);
  servo4.attach(SERVO_4_PIN);

  writeFourFinMixer(0.0f, 0.0f);
  previousLoopUs = micros();

  Serial.println("PID Rocket ESP32 control loop starter");
}

void loop() {
  const uint32_t nowUs = micros();
  if (nowUs - previousLoopUs < CONTROL_LOOP_INTERVAL_US) {
    return;
  }

  lastLoopDtUs = nowUs - previousLoopUs;
  previousLoopUs = nowUs;

  const float dtSeconds = static_cast<float>(lastLoopDtUs) / 1000000.0f;
  const float rollDeg = readRollDeg();
  const float pitchDeg = readPitchDeg();

  const float rollOutput = rollPid.update(SETPOINT_ROLL_DEG, rollDeg, dtSeconds);
  const float pitchOutput = pitchPid.update(SETPOINT_PITCH_DEG, pitchDeg, dtSeconds);

  writeFourFinMixer(rollOutput, pitchOutput);

  loopCount++;
  if (loopCount % 500 == 0) {
    printTiming(rollDeg, pitchDeg, rollOutput, pitchOutput);
  }
}
