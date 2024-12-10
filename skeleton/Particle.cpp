#include "Particle.h"

Particle::Particle(physx::PxVec3 Pos)
{
	pose = physx::PxTransform(Pos);
	pos = Pos;
	vel = { 0,0,0 };
	ace = { 0,0,0 };
	color = { 1, 0, 1, 1 };

	item = new RenderItem
	(CreateShape(physx::PxBoxGeometry(Vector3{ 5,5,5 })),
		&pose, color);
	createCaja(pos, 5, 5, 5);
}

Particle::Particle(physx::PxVec3 Pos, float r, Vector4 col)
{
	pose = physx::PxTransform(Pos);
	vel = { 0,0,0 };
	ace = { 0,0,0 };
	color = col;

	item = new RenderItem
	(CreateShape(physx::PxSphereGeometry(r)),
		&pose, color);

	createCaja(pose.p, r, r, r);
}

Particle::Particle(physx::PxVec3 Pos, physx::PxVec3 Vel, Vector4 col)
{
	pose = physx::PxTransform(Pos);
	pos = Pos;
	vel = Vel;
	ace = Vector3(0, 0, 0);
	color = col;

	item = new RenderItem
	(CreateShape(physx::PxSphereGeometry(5)),
		&pose, color);

	createCaja(pos, 5, 5, 5);
}

Particle::Particle(physx::PxVec3 Pos, Vector4 col, physx::PxVec3 a, double D)
{
	pose = physx::PxTransform(Pos);
	pos = Pos;
	ace = a;
	d = D;
	color = col;

	item = new RenderItem
	(CreateShape(physx::PxSphereGeometry(5)),
		&pose, col);

	createCaja(pos, 5, 5, 5);
}

Particle::Particle(physx::PxVec3 Pos, physx::PxVec3 Vel, Vector4 col, physx::PxVec3 a, double D)
{
	pose = physx::PxTransform(Pos);
	pos = Pos;
	vel = Vel;
	ace = a;
	d = D;
	color = col;

	item = new RenderItem
	(CreateShape(physx::PxSphereGeometry(5)), 
		&pose, col);

	createCaja(pos, 5, 5, 5);
}

Particle::~Particle()
{
	DeregisterRenderItem(item);
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

	if (liveTime <= 0) alive = false;
}

void Particle::setVisibility(bool vi)
{
	if (vi && !visibility) {
		RegisterRenderItem(item); 
		visibility = vi;
	}
	else if (!vi && visibility) {
		DeregisterRenderItem(item);
		visibility = vi;
	}
}

void Particle::setTam(float r, int shape)
{
	//Tengo que buscar una manera de eliminar el enterior
	DeregisterRenderItem(item);

	switch (shape) {

	case 0:		//Es un circulo
		item = new RenderItem
		(CreateShape(physx::PxSphereGeometry(r)),
			&pose, color);
		createCaja(pose.p, r, r, r);
		break;
	case 1:		//Es un cuadrado
		item = new RenderItem
		(CreateShape(physx::PxBoxGeometry(Vector3{ r,1,r })),
			&pose, color);
		createCaja(pose.p, r, 1, r);
		break;

	}
}
