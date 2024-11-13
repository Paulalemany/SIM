#include "ParticleSystemFuente.h"

ParticleSystemFuente::ParticleSystemFuente(Vector3 ori, Vector3 vel, int n, int l)
	: ParticleSystem(ori, vel, n, l, 1)
{
	generator = new FuenteGenerator(origen, velMed, numParticles);
}

bool ParticleSystemFuente::update(double t)
{
	return ParticleSystem::update(t);
}
