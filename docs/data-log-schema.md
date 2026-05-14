# Flight Data Log Schema

Use CSV for the first logging format so Python, MATLAB, and spreadsheet tools can all read it.

## File Naming

```text
YYYYMMDD_test-name_run-##.csv
```

Example:

```text
20260615_bench-tilt_run-01.csv
```

## Fields

| Field | Unit | Source | Notes |
| --- | --- | --- | --- |
| `time_us` | microseconds | ESP32 | Monotonic timestamp from boot |
| `loop_dt_us` | microseconds | ESP32 | Actual control loop delta |
| `phase` | enum | firmware | `idle`, `armed`, `boost`, `coast`, `descent`, `landed` |
| `accel_x_g` | g | IMU | Raw or calibrated, document which |
| `accel_y_g` | g | IMU | Raw or calibrated, document which |
| `accel_z_g` | g | IMU | Raw or calibrated, document which |
| `gyro_x_dps` | deg/s | IMU | Raw or calibrated |
| `gyro_y_dps` | deg/s | IMU | Raw or calibrated |
| `gyro_z_dps` | deg/s | IMU | Raw or calibrated |
| `roll_deg` | degrees | estimator | Estimated attitude |
| `pitch_deg` | degrees | estimator | Estimated attitude |
| `baro_alt_m` | meters | BMP390 | Relative altitude after zeroing |
| `pressure_pa` | pascal | BMP390 | Ambient pressure |
| `gps_lat` | degrees | GPS | Optional until GPS lock |
| `gps_lon` | degrees | GPS | Optional until GPS lock |
| `gps_alt_m` | meters | GPS | Optional until GPS lock |
| `pid_roll` | command | PID | Roll controller output before mixing |
| `pid_pitch` | command | PID | Pitch controller output before mixing |
| `servo_1_deg` | degrees | mixer | Commanded servo angle |
| `servo_2_deg` | degrees | mixer | Commanded servo angle |
| `servo_3_deg` | degrees | mixer | Commanded servo angle |
| `servo_4_deg` | degrees | mixer | Commanded servo angle if used |
| `battery_v` | volts | ADC | Add once voltage divider exists |

## Logging Rule

Every test run should have a matching note in `logs/build-log.md` with hardware configuration, firmware commit, gains, and observed behavior.
