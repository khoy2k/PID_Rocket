# Bill of Materials

Estimated hardware budget from planning document: `$100-150 USD`.

## Core Stack

| Priority | Component | Candidate Part | Purpose | Notes |
| --- | --- | --- | --- | --- |
| P0 | Flight computer | ESP32 DevKit | Real-time controller and logging coordinator | PlatformIO, Arduino framework |
| P0 | IMU | MPU-6050 | Accel/gyro attitude input | Initial 500 Hz target; verify noise and mounting |
| P0 | Servo actuator | MG996R or DS3225 | Active fin movement | Bench-test speed and torque before final choice |
| P0 | Power | LiPo + BEC/regulator | Servo 5 V and ESP32/sensor 3.3 V | Separate power integrity test required |
| P1 | Barometer | BMP390 | Altitude and pressure logging | Use for flight phase and post-flight analysis |
| P1 | SD card module | SPI microSD module | Flight data logging | Must pass pre-launch write test |
| P1 | GPS | NEO-M9N or BN-880 | Recovery and post-flight position | Decide after antenna/lock test |
| P1 | Airframe | TBD carbon fiber | Rocket body | Re-check CG/CP after every change |

## First Purchase Recommendation

Buy only enough to prove the bench loop:

- ESP32 DevKit.
- 1x MPU-6050 breakout.
- 1x servo for sign/direction testing.
- 5 V BEC or bench supply.
- Jumper wires, breadboard, and a small mounting jig.

Delay GPS, final servos, and airframe purchases until the control loop direction, timing, and data schema are stable.

## Decision Log

| Date | Decision | Reason |
| --- | --- | --- |
| TBD | Fin count | Choose 3 vs 4 after mechanical complexity and control mixing are compared |
| TBD | Servo model | Choose after loaded response test; pass target is under 50 ms response |
| TBD | GPS module | Choose after cold/warm lock and logging tests |
