% =========================================================
% Active Rocket Design Tool
% Author: Hoo Kang | Summer 2026
% =========================================================
clear; clc;
thrust_data;


% 1. Load parameters
vehicle = vehicle_params();

% 2. Aero
CP = barrowman_cp(vehicle);

% 3. Mass
CG = cg_calc(vehicle);

% 4. Stability
SM = (CP - CG) / vehicle.diameter;

% 5. Output
fprintf('=================\n');
fprintf('CP: %.4f m\n', CP);
fprintf('CG: %.4f m\n', CG);
fprintf('SM: %.2f cal\n', SM);
fprintf('=================\n');

if SM < 1.5
    warning('SM too low. Redesign needed.');
elseif SM > 2.5
    warning('SM too high. Canard authority may be reduced.');
end