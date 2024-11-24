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

std::vector<Proyectil*> ParticleGenerator::CreateParticles()
{
	return std::vector<Proyectil*>();
}
