#include "Proyectil.h"
#include <iostream>

Proyectil::Proyectil(physx::PxVec3 Pos, physx::PxVec3 Vel, Vector4 col, physx::PxVec3 a, double D, double m)
	: Particle(Pos, Vel, col, a, D)
{
	//Escalamos las medidas
	masa = m * 0.4;
	gr = masa * -9.8;	//Esta sería la componente y ya que la gravedad solo afecta hacia abajo

	vel = Vel * 0.05;
}

bool Proyectil::update(double t)
{

	//Actualizamos la masa
	integrate(t);

	return true;
}
