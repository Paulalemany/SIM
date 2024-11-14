#include "Particle.h"
#include <iostream>

Particle::Particle(physx::PxVec3 Pos, physx::PxVec3 Vel, Vector4 color)
{
	pose = physx::PxTransform(Pos);
	pos = Pos;
	vel = Vel;
	ace = Vector3(0, 0, 0);

	renderItem = new RenderItem
	(CreateShape(physx::PxSphereGeometry(5)),
		&pose, color);
}

Particle::Particle(physx::PxVec3 Pos, Vector4 col, physx::PxVec3 a, double D)
{
	pose = physx::PxTransform(Pos);
	ace = a;
	d = D;

	renderItem = new RenderItem
	(CreateShape(physx::PxSphereGeometry(5)),
		&pose, col);
}

Particle::Particle(physx::PxVec3 Pos, physx::PxVec3 Vel, Vector4 col, physx::PxVec3 a, double D)
{
	pose = physx::PxTransform(Pos);
	pos = Pos;
	vel = Vel;
	ace = a;
	d = D;
	color = col;

	renderItem = new RenderItem
	(CreateShape(physx::PxSphereGeometry(5)), 
		&pose, col);
}

Particle::~Particle()
{
	DeregisterRenderItem(renderItem);
}

void Particle::integrate(double t)
{
	//euler semi-implicito
	vel = vel + t * ace;
	pose.p = pose.p + t * vel;
	vel = vel * pow(d, t);

	//Hay que borrar las fuerzas
}

bool Particle::update(double t)
{
	if (!alive) return false;

	//Actualizamos la posición si está viva
	integrate(t);
	return true;
}

void Particle::restLiveTime(double t)
{
	liveTime -= t;
}
