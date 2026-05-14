# ESP32 Firmware Starter

This is a PlatformIO starter for the avionics control loop.

Current purpose:

- Prove a measured 500 Hz loop.
- Keep servo output clamped around neutral.
- Share one PID implementation between bench tests and future HIL vectors.

It is not flight-ready. Sensor drivers, estimator code, SD logging, arming logic, and actuator mixing still need to be implemented and tested.

## First Bring-Up

```bash
platformio run
platformio run --target upload
platformio device monitor
```

Expected serial output:

- Loop timing every 500 cycles.
- Servo commands near neutral because sensor readings are currently placeholders.

## Next Firmware Tasks

- Add MPU-6050 readout.
- Confirm axis convention and sign.
- Add complementary/Kalman attitude estimator.
- Add CSV logging to SD.
- Add HIL input mode for simulated sensor data.
- Add arming and failsafe state machine.
