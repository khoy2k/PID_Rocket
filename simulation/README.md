# Simulation Workspace

Use this directory for Simulink, MATLAB, and model notes.

Phase 1 model target:

- 6DOF rigid body dynamics.
- Motor thrust curve input.
- Aerodynamic drag model.
- Fin deflection input.
- Open-loop comparison against OpenRocket.
- PID controller tuning records.

Recommended first model:

1. Start with pitch-only rotational dynamics.
2. Add roll axis.
3. Add actuator saturation and rate limit.
4. Add disturbance input.
5. Compare firmware PID output against Simulink output for identical test vectors.
