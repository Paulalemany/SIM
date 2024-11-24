#include "ParticleGenerator.h"

ParticleGenerator::ParticleGenerator(Vector3 o, Vector3 vel, int np)
{
	origen = o;
	velMed = vel;
	numParticles = np;
}

ParticleGenerator::ParticleGenerator(Vector3 o, Vector3 vel, int np, Vector4 col)
{
	origen = o;
	velMed = vel;
	numParticles = np;
	color = col;
}

std::vector<Particle*> ParticleGenerator::CreateParticles()
{
	return std::vector<Particle*>();
}
