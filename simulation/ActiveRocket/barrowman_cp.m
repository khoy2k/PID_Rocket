function CP = barrowman_cp(vehicle)

d  = vehicle.diameter;
Ar = pi * (d/2)^2;

% Nose
C_N_nose = 2;
x_nose   = 0.466 * vehicle.nose.length;

% Canard
n_c  = vehicle.canard.count;
s_c  = vehicle.canard.span;        % semi-span, 나누기 제거
lm_c = vehicle.canard.sweep;
cr_c = vehicle.canard.root;
ct_c = vehicle.canard.tip;

C_N_canard = (4*n_c*(s_c/d)^2) / (1 + sqrt(1 + (2*lm_c/(cr_c+ct_c))^2));
x_canard   = vehicle.canard.x_le ...
           + (lm_c/3)*((cr_c + 2*ct_c)/(cr_c + ct_c)) ...
           + (1/6)*(cr_c + ct_c - (cr_c*ct_c)/(cr_c+ct_c));

% Fin
n_f  = vehicle.fin.count;
s_f  = vehicle.fin.span;           % semi-span, 나누기 제거
lm_f = vehicle.fin.sweep;
cr_f = vehicle.fin.root;
ct_f = vehicle.fin.tip;

C_N_fin = (4*n_f*(s_f/d)^2) / (1 + sqrt(1 + (2*lm_f/(cr_f+ct_f))^2));
x_fin   = vehicle.fin.x_le ...
        + (lm_f/3)*((cr_f + 2*ct_f)/(cr_f + ct_f)) ...
        + (1/6)*(cr_f + ct_f - (cr_f*ct_f)/(cr_f+ct_f));

% CP
CN_tot = C_N_nose + C_N_canard + C_N_fin;
CP = (C_N_nose*x_nose + C_N_canard*x_canard + C_N_fin*x_fin) / CN_tot;

end