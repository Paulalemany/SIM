#include "Particle.h"
#include <iostream>

Particle::Particle(physx::PxVec3 Pos)
{
	pose = physx::PxTransform(Pos);
	pos = Pos;
	vel = { 0,0,0 };
	ace = { 0,0,0 };
	color = { 1, 0, 1, 1 };

	renderItem = new RenderItem
	(CreateShape(physx::PxBoxGeometry(Vector3{ 5,5,5 })),
		&pose, color);
}

Particle::Particle(physx::PxVec3 Pos, float r)
{
	pose = physx::PxTransform(Pos);
	pos = Pos;
	vel = { 0,0,0 };
	ace = { 0,0,0 };
	color = { 0.33, 0.39, 0.92, 0.5 };

	renderItem = new RenderItem
	(CreateShape(physx::PxBoxGeometry(Vector3{ r,r,r })),
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

void Particle::setTam(float r, int shape)
{
	//Tengo que buscar una manera de eliminar el enterior
	DeregisterRenderItem(renderItem);

	switch (shape) {

	case 0:		//Es un circulo
		renderItem = new RenderItem
		(CreateShape(physx::PxSphereGeometry(r)),
			&pose, color);
		break;
	case 1:		//Es un cuadrado
		renderItem = new RenderItem
		(CreateShape(physx::PxBoxGeometry(Vector3{ r,r,r })),
			&pose, color);
		break;

	}
}
