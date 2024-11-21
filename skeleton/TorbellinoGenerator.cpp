#include "TorbellinoGenerator.h"

Vector3 TorbellinoGenerator::generateForce(Particle& p)
{
	Vector3 F(0, 0, 0),
		partPos = p.getPosition();

	F = k * Vector3(-(partPos.z - origen.z), 
					50 - (partPos.y - origen.y), 
					partPos.x - origen.x);

	F -= p.getVelocity();

	return F;
}
