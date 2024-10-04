#pragma once
#include "Particle.h"
#include <PxPhysicsAPI.h>

class Proyectil : protected Particle
{
public:
	//Constructora
	Proyectil(physx::PxVec3 Pos, physx::PxVec3 Vel, Vector4 col, physx::PxVec3 a, double D, double m);

	bool update(double t);

private:

	//Masa en gramos
	double masa = 0;

	//Gravedad en m/s
	double gr = 0;	
	double gs = 0;

	//Velocidad en m/s
	
};

