#include "Particle.h"

Particle::Particle(physx::PxVec3 Pos, physx::PxVec3 Vel)
{
	pose = physx::PxTransform(Pos);
	vel = Vel;

	renderItem = new RenderItem(CreateShape(physx::PxSphereGeometry(5)), &pose, Vector4(1, 0.7, 0.8, 1));
	RegisterRenderItem(renderItem);
}

Particle::~Particle()
{
	DeregisterRenderItem(renderItem);
}

void Particle::integrate(double t)
{
	pose.p = pose.p + t * vel;
}
