#pragma once

#include <Arduino.h>
#include <math.h>

class PIDController {
public:
  PIDController(float kp, float ki, float kd, float outputLimit)
      : kp_(kp), ki_(ki), kd_(kd), outputLimit_(fabsf(outputLimit)) {}

  void setGains(float kp, float ki, float kd) {
    kp_ = kp;
    ki_ = ki;
    kd_ = kd;
  }

  void reset() {
    integral_ = 0.0f;
    previousError_ = 0.0f;
    hasPrevious_ = false;
  }

  float update(float setpoint, float measured, float dtSeconds) {
    if (dtSeconds <= 0.0f) {
      return lastOutput_;
    }

    const float error = setpoint - measured;
    integral_ += error * dtSeconds;

    const float derivative = hasPrevious_ ? (error - previousError_) / dtSeconds : 0.0f;
    float output = (kp_ * error) + (ki_ * integral_) + (kd_ * derivative);

    if (output > outputLimit_) {
      output = outputLimit_;
    } else if (output < -outputLimit_) {
      output = -outputLimit_;
    }

    previousError_ = error;
    hasPrevious_ = true;
    lastOutput_ = output;
    return output;
  }

private:
  float kp_ = 0.0f;
  float ki_ = 0.0f;
  float kd_ = 0.0f;
  float outputLimit_ = 20.0f;
  float integral_ = 0.0f;
  float previousError_ = 0.0f;
  float lastOutput_ = 0.0f;
  bool hasPrevious_ = false;
};
