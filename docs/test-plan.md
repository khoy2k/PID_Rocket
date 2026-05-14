# Test Plan

## Pass Criteria

| Test | Method | Pass Criteria |
| --- | --- | --- |
| Sensor verify | Static bench read | IMU, barometer, and GPS report valid data |
| Loop timing | Serial timing print | Control loop holds target rate or stable measured rate is documented |
| Servo response | Step input with timing measurement | Response under 50 ms |
| PID bench | Tilt vehicle and observe fins | Fins correct in the right direction for pitch and roll |
| HIL validation | Simulink input vs ESP32 output | Under 5% output deviation |
| Pre-launch CG/CP | Physical balance plus OpenRocket | Stability over 1.5 calibers |
| Test launch | Full flight with SD log and video | Stable ascent observed and log recovered |

## Phase 0 Bench Procedure

1. Flash firmware with neutral servo output.
2. Confirm servo moves to neutral on boot.
3. Enable serial loop timing output.
4. Verify measured loop interval is close to `2000 us`.
5. Add IMU readout.
6. Confirm pitch/roll axes by rotating the avionics mount by hand.
7. Enable PID output with conservative gains.
8. Confirm servo direction for pitch and roll.
9. Save log sample to `data/raw/`.
10. Add notes to `logs/build-log.md`.

## Pre-Launch Gate

Do not launch until all items are true:

- Simulink model has current mass, CG, CP, motor, and environment assumptions.
- HIL comparison has passed.
- Servo response has passed under realistic load.
- SD logging has passed with backup card.
- CG/CP was re-measured after final assembly.
- Active fin mechanism passed static load testing.
