#include "Particle.h"

Particle::Particle(physx::PxVec3 Pos, physx::PxVec3 Vel)
{
	pose = physx::PxTransform(Pos);
	vel = Vel;
	ace = Vector3(0, 0, 0);

	renderItem = new RenderItem
	(CreateShape(physx::PxSphereGeometry(5)),
		&pose, Vector4(1, 0.7, 0.8, 1));
}

Particle::Particle(physx::PxVec3 Pos, physx::PxVec3 Vel, physx::PxVec3 a, double D)
{
	pose = physx::PxTransform(Pos);
	vel = Vel;
	ace = a;
	d = D;

	renderItem = new RenderItem
	(CreateShape(physx::PxSphereGeometry(5)), 
		&pose, Vector4(1, 0.7, 0.8, 1));
}

Particle::~Particle()
{
	DeregisterRenderItem(renderItem);
}

void Particle::integrate(double t)
{
	pose.p = pose.p + t * vel;
	vel = vel + t * ace;
	vel = vel * pow(d, t);
}
