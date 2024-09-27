#pragma once
#include "RenderUtils.hpp"
#include <PxPhysicsAPI.h>

class Particle
{
public:
	Particle(physx::PxVec3 Pos, physx::PxVec3 Vel);
	~Particle();

	void integrate(double t);

private:
	physx::PxVec3 vel;
	//0 < d < 1
	int d = 0.98;

	//Al RenderItem le pasamos pose para que se actualice automaticamente
	physx::PxTransform pose;
	RenderItem* renderItem;

};

