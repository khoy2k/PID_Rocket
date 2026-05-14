# Control System Notes

## Baseline Architecture

Target loop rates:

- IMU attitude estimation: `500 Hz`.
- GPS/barometer logging: `10 Hz`.
- Servo command output: tied to control loop unless later rate-limited.

Control path:

```text
MPU-6050 IMU
  -> attitude estimation / Kalman filter
  -> PID controller
  -> servo PWM output
  -> fin actuators
  -> vehicle attitude correction
  -> IMU feedback
```

Supporting sensors:

- BMP390: pressure and altitude logging.
- GPS: recovery and post-flight track.
- SD card: complete telemetry log.

## Initial Setpoints

- Roll: `0 deg`.
- Pitch: `0 deg`.
- Yaw: not controlled in the first firmware skeleton.

The first implementation should only prove pitch/roll sign convention and timing. It should not be treated as flight-ready guidance.

## PID Sign Convention

Use the same error convention in Simulink and firmware:

```text
error = setpoint - measured_angle
output = Kp * error + Ki * integral(error) + Kd * derivative(error)
```

Bench test requirement:

- Tilt vehicle nose in +pitch direction.
- Confirm the pitch correction output commands fins in the direction that pushes pitch back toward `0 deg`.
- Repeat for -pitch, +roll, and -roll.

## First Mixing Model

Start with independent pitch and roll corrections, then map them to fin commands after fin count is decided.

For early bench tests:

- Servo neutral: `90 deg`.
- Max deflection from neutral: `20 deg`.
- Clamp PID output before servo command.

The final mixer depends on whether the mechanism uses 3 or 4 active fins.
