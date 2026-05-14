# Active Flight Control Rocket

PID-based active fin control rocket project by Kang and Andrew Lee, planned for Summer 2026.

This repo is the working home for the simulation, avionics firmware, mechanical design notes, test records, and post-flight analysis for a high-power rocket with real-time attitude correction.

## Current Starting Point

The project should begin with a narrow Phase 0 baseline before buying parts or building the airframe:

1. Freeze the initial control architecture and data log format.
2. Build a first-order pitch/roll simulation or Simulink model.
3. Bring up an ESP32 firmware loop that runs at a measured 500 Hz.
4. Validate PID sign conventions with bench servo motion before any flight hardware integration.

The first technical milestone is not a launch. It is a reproducible bench loop: simulated or manually tilted attitude input, PID output, servo deflection, and SD-ready telemetry fields.

## Engineering Goals

- Stabilize rocket attitude using PID control and active fin actuators.
- Validate controller behavior in Simulink before embedded implementation.
- Port the controller to ESP32 using PlatformIO.
- Log full flight data for post-flight analysis.
- Run a small H/I class test launch only after simulation, HIL, and bench tests pass.

## Repo Map

| Path | Purpose |
| --- | --- |
| `docs/` | Project plan, BOM, test plan, control design notes |
| `firmware/esp32/` | PlatformIO ESP32 avionics firmware starter |
| `simulation/` | Simulink/MATLAB model notes and future model files |
| `fusion360/` | Fin actuator and airframe integration exports/notes |
| `analysis/` | Python/MATLAB post-flight analysis scripts |
| `logs/` | Build log and dated engineering notes |
| `data/raw/` | Raw SD card logs, excluded except `.gitkeep` |
| `data/processed/` | Cleaned analysis outputs, excluded except `.gitkeep` |

## First Sprint

Target outcome: a bench-testable control loop skeleton.

- Confirm 3-fin vs 4-fin actuator layout.
- Pick temporary servo hardware for bench testing.
- Implement and measure ESP32 loop timing.
- Confirm IMU axis orientation convention.
- Create a minimal Simulink or MATLAB pitch/roll model.
- Run manual tilt tests and verify fins correct in the expected direction.

## Safety Note

This repo should treat active control as flight-critical. Any code that drives actuators needs bench validation, logging, and a pre-launch checklist before it is considered flight-ready.
