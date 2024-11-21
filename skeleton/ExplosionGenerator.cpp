#include "ExplosionGenerator.h"

void ExplosionGenerator::setRadio(float r)
{
	radio = r;
	generateZone();
}

void ExplosionGenerator::update(double t)
{
	//en el momento que es mayor a 4 ya se esta desvaneciendo
	if (time <= 4 * q) {
		time += t;
		setRadio(vel * time);
	}
}

Vector3 ExplosionGenerator::generateForce(Particle& p)
{
	Vector3 F = { 0,0,0 };

	if (time < 0 || time >= 4 * q) return F;

	float r = (p.getPosition() - origen).magnitude();

	F = ((k / r * r) * (p.getPosition() - origen)) * exp(-time / q);

	return F;
}
