function vehicle = vehicle_params()
%INPUT: vehicle struct parameter
%OUTPUT: CP location(m, origin at nose cone) 
%   Detailed explanation goes here

% ── airframe ──────────────────────────────────────────────
vehicle.diameter    = 0.076;        % 3 inch airframe (m)
vehicle.length      = 1.2;          % total length (m)
 
% ── nose ────────────────────────────────────────────
vehicle.nose.type   = 'ogive';      % ogive / conical / parabolic
vehicle.nose.length = 0.25;         % nose length (m)
 
% ── main fin (n =4 ) ──────────────────────────────────
vehicle.fin.count   = 4;
vehicle.fin.root    = 0.10;         % root chord  (m)
vehicle.fin.tip     = 0.05;         % top chord (m)
vehicle.fin.span    = 0.08;         % semi span (m)
vehicle.fin.sweep   = 0.06;         % mid chord sweep l  (m)
vehicle.fin.x_le    = 1.05;         % fin leading x distance (m)
 
% ── canard ────────────────────────────────────────────
vehicle.canard.count  = 4;
vehicle.canard.root   = 0.05;
vehicle.canard.tip    = 0.025;
vehicle.canard.span   = 0.04;
vehicle.canard.sweep  = 0.03;
vehicle.canard.x_le   = 0.30;       % From nose
 
% ── mass distribution ─────────────────────────────────────────
vehicle.mass.nosecone   = 0.08;     % kg, x = nose.length/2
vehicle.mass.airframe   = 0.25;     % kg, x = length/2
vehicle.mass.avionics   = 0.15;     % kg, x = 0.5 (avionics bay)
vehicle.mass.motor      = 0.35;     % kg, x = length - 0.1
vehicle.mass.recovery   = 0.10;     % kg, x = 0.4














end