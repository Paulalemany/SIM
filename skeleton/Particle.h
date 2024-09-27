#pragma once
#include "RenderUtils.hpp"
#include <PxPhysicsAPI.h>

class Particle
{
public:
	Particle(physx::PxVec3 Pos, physx::PxVec3 Vel, Vector4 col);
	Particle(physx::PxVec3 Pos, physx::PxVec3 Vel, Vector4 col, physx::PxVec3 a, double D);
	~Particle();

	void integrate(double t);

private:
	physx::PxVec3 vel;
	physx::PxVec3 ace;

	//0 < d < 1
	double d = 0.98;

	//Al RenderItem le pasamos pose para que se actualice automaticamente
	physx::PxTransform pose;
	RenderItem* renderItem;

};

