#include "ParticleSystemHumo.h"

ParticleSystemHumo::ParticleSystemHumo(Vector3 ori, Vector3 vel, int n, int l)
	: ParticleSystem(ori, vel, n, l, 1)
{
	generator = new HumoGenerator(origen, velMed, numParticles);
}

bool ParticleSystemHumo::update(double t)
{
	return ParticleSystem::update(t);
}
