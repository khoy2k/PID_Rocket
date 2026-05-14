# Project Plan

Source baseline: `Active Flight Control Rocket - Project Documentation`, Version 1.0.

## Phase 0 - Repo and Architecture Baseline

Goal: establish the engineering ground rules before hardware decisions harden.

Deliverables:

- Project repo structure.
- Initial BOM and hardware decision log.
- Control loop architecture.
- Telemetry CSV schema.
- ESP32 firmware skeleton with a 500 Hz loop target.
- Bench test matrix.

Exit criteria:

- Open questions are tracked.
- Firmware loop timing can be measured on serial output.
- PID sign convention is documented.
- Data fields needed for Simulink, HIL, and post-flight analysis are named.

## Phase 1 - Simulink Modeling

Goal: build a 6DOF rigid body flight dynamics model before committing to flight code.

Tasks:

- Add motor thrust curve input.
- Add drag model from OpenRocket or a simplified coefficient model.
- Add fin deflection as control input.
- Compare open-loop stability with OpenRocket CG/CP prediction.
- Document assumptions for mass, inertia, fin area, and air density.

Target: Early Summer 2026.

## Phase 2 - PID Controller Design

Goal: tune pitch and roll stabilization in simulation.

Tasks:

- Define setpoints: roll `0 deg`, pitch `0 deg`, vertical flight reference.
- Tune `Kp`, `Ki`, and `Kd` gains in Simulink.
- Run step response tests.
- Run disturbance rejection tests.
- Record gain margin and phase margin when available.

Target: Mid Summer 2026.

## Phase 3 - Hardware-in-the-Loop Validation

Goal: prove ESP32 output matches simulation output before bench-integrating the full stack.

Tasks:

- Port PID controller from Simulink to C/C++.
- Feed simulated sensor data into ESP32.
- Compare ESP32 servo command output against Simulink expected output.
- Measure control loop timing.

Exit criteria:

- HIL output deviation is under 5%.
- 500 Hz loop target is measured or the actual stable rate is documented.

Target: Late Summer 2026.

## Phase 4 - Bench Test

Goal: verify the full avionics stack without launch risk.

Tasks:

- Connect IMU, barometer, GPS, SD card, BEC, and servos.
- Verify sensor readings.
- Verify servo response time under load.
- Manually tilt the vehicle and confirm fin response direction.
- Record SD logs and parse them in `analysis/`.

Target: Late Summer 2026.

## Phase 5 - Test Launch

Goal: run a small H/I class flight only after the simulation and bench gates pass.

Tasks:

- Re-check physical CG/CP after final hardware integration.
- Update simulation with site altitude, temperature, and wind.
- Record video.
- Recover SD log.
- Compare logged attitude data against Simulink prediction.

Target: End of Summer 2026.

## Open Questions

- GPS module: NEO-M9N or BN-880?
- Active fin count: 3 or 4?
- Test motor class: H or I?
- Airframe material and source?
- Launch site?
- IMU upgrade path if MPU-6050 noise/drift is too high?
