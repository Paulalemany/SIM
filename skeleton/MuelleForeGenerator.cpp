#include "MuelleForeGenerator.h"

MuelleForeGenerator::MuelleForeGenerator(Vector3 ori, double _k, double rl, Particle* p)
	: ForceGenerator(ori)
{
	_k = k;
	resting_length = rl;
	par = p;
}

void MuelleForeGenerator::updateForce(Particle* p)
{
	//Particle par es el origen
	Vector3 relativePos = par->getPosition() - p->getPosition();
	Vector3 F;

	//Normalizamos el vector
	const float largo = relativePos.normalize();
	const float deltaX = largo - resting_length;

	F = relativePos * deltaX * k;

	p->addForce(F);
}
