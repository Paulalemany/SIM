#pragma once
#include "Particle.h"
#include <PxPhysicsAPI.h>

class Proyectil : protected Particle
{
public:
	//Constructora
	Proyectil(physx::PxVec3 Pos, physx::PxVec3 Vel, Vector4 col, physx::PxVec3 a, double D, double m);

private:

	double masa = 0;
	double gravity = 0;
};

