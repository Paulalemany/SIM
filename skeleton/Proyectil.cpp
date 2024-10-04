#include "Proyectil.h"

Proyectil::Proyectil(physx::PxVec3 Pos, physx::PxVec3 Vel, Vector4 col, physx::PxVec3 a, double D, double m)
	: Particle(Pos, Vel, col, a, D)
{
	masa = m;
	gravity = masa * -9.8;	//Esta sería la componente y ya que la gravedad solo afecta hacia abajo
}
