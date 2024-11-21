#include "VientoGenerator.h"

VientoGenerator::VientoGenerator(Vector3 ori, Vector3 v)
	: ForceGenerator(ori)
{
	viento = v;
}

Vector3 VientoGenerator::generateForce(Particle& p)
{
	Vector3 F = { 0,0,0 };

	//Calculo de la fuerza del viento
	F = k1 * (viento - p.getVelocity()) + k2;

	return F;
}
