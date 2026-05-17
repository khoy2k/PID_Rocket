function CG = cg_calc(vehicle)

masses = [
    vehicle.mass.nosecone,  vehicle.nose.length / 2;
    vehicle.mass.airframe,  vehicle.length / 2;
    vehicle.mass.avionics,  0.50;
    vehicle.mass.motor,     vehicle.length - 0.10;
    vehicle.mass.recovery,  0.40;
];

total_mass = sum(masses(:,1));
CG = sum(masses(:,1) .* masses(:,2)) / total_mass;

end