#include "Proyectil.h"
#include <iostream>

//La aceleración es a + gravedad
//El color de estos va a ser morado
Proyectil::Proyectil(physx::PxVec3 Pos, physx::PxVec3 Vel, physx::PxVec3 a, double D)
	: Particle(Pos, Vel, Vector4 (0.34, 0.13, 0.39, 1), a + Vector3(0, -9.8, 0), D)
{
	//Escalamos las medidas
	//masa = m * 0.4;
	//gr = masa * -9.8;	//Esta sería la componente y ya que la gravedad solo afecta hacia abajo

	//vel = Vel * 0.05;
}

bool Proyectil::update(double t)
{
	// si esta por debajo de una posicion, marca la particula para eliminar
	//if (pose.p.y <= 10) alive = false;

	return Particle::update(t);
}
