#include "Particle.h"
#include <iostream>

Particle::Particle(physx::PxVec3 Pos)
{
	pose = physx::PxTransform(Pos);
	vel = { 0,0,0 };
	ace = { 0,0,0 };
	color = { 1, 0, 1, 1 };

	renderItem = new RenderItem
	(CreateShape(physx::PxBoxGeometry(Vector3{ 5,5,5 })),
		&pose, color);
}

Particle::Particle(physx::PxVec3 Pos, float r, Vector4 col)
{
	pose = physx::PxTransform(Pos);
	vel = { 0,0,0 };
	ace = { 0,0,0 };
	color = col;

	renderItem = new RenderItem
	(CreateShape(physx::PxSphereGeometry(r)),
		&pose, color);
}

Particle::Particle(physx::PxVec3 Pos, physx::PxVec3 Vel, Vector4 col)
{
	pose = physx::PxTransform(Pos);
	pos = Pos;
	vel = Vel;
	ace = Vector3(0, 0, 0);
	color = col;

	renderItem = new RenderItem
	(CreateShape(physx::PxSphereGeometry(5)),
		&pose, color);
}

Particle::Particle(physx::PxVec3 Pos, Vector4 col, physx::PxVec3 a, double D)
{
	pose = physx::PxTransform(Pos);
	pos = Pos;
	ace = a;
	d = D;
	color = col;

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

	pos = pose.p;
}

bool Particle::update(double t)
{
	restLiveTime(t);

	if (!alive) return false;

	//Actualizamos la posición si está viva
	integrate(t);
	return true;
}

void Particle::restLiveTime(double t)
{
	liveTime -= t;
}

void Particle::setVisibility(bool vi)
{
	if (vi) RegisterRenderItem(renderItem);
	else DeregisterRenderItem(renderItem);
}
