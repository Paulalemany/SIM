#include "ParticleGenerator.h"

ParticleGenerator::ParticleGenerator(Vector3 o, Vector3 vel, int np)
{
	origen = o;
	velMed = vel;
	numParticles = np;

	new Particle(o, vel, Vector4(1, 1, 1, 1));
}

ParticleGenerator::ParticleGenerator(Vector3 o, Vector3 vel, int np, Vector4 col)
{
	origen = o;
	velMed = vel;
	numParticles = np;
	color = col;

	new Particle(o, vel, color);
}
