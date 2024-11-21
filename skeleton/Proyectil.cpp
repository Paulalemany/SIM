#include "Proyectil.h"
#include <iostream>

Proyectil::Proyectil(Proyectil* p)
	: Particle (p->pos, p->vel, p->color, p->ace, p->d)
{
	//Copiamos la particula que se pasa
	grav = Vector3(0, -9.8, 0);
}

//La aceleración es a + gravedad
//El color de estos va a ser morado
Proyectil::Proyectil(physx::PxVec3 Pos, physx::PxVec3 Vel, physx::PxVec3 a, double D)
	: Particle(Pos, Vel, Vector4 (0.34, 0.13, 0.39, 1), a + Vector3(0, -9.8, 0), D)
{
	grav = Vector3(0, -9.8, 0);
}

Proyectil::Proyectil(physx::PxVec3 Pos, physx::PxVec3 Vel, physx::PxVec3 a, double D, Vector4 color)
	: Particle(Pos, Vel, color, a + Vector3(0, -9.8, 0), D)
{
	grav = Vector3(0, -9.8, 0);
}

bool Proyectil::update(double t)
{
	// si esta por debajo de una posicion, marca la particula para eliminar
	/*if (pose.p.y <= -50 || pose.p.y >= 70) {
		alive = false; 
	}
	else if (liveTime <= 0)
	{
		alive = false;
	}*/

	applyForces();

	return Particle::update(t);
}

void Proyectil::applyForces()
{
	//Calculamos la fuerza total que hay sobre la particula
	//Lo hacemos con un sumatorio

	Vector3 FuerzaTot = { 0,0,0 };
	for (auto f : fuerzas) FuerzaTot += f;

	//hay que limpiar el vector de fuerzas???
	//fuerzas.clear();

	//La fuerza resultante sigue la formula F = m * a

	ace = FuerzaTot / masa;

	//Le sumamos la gravedad
	ace += grav;
}
