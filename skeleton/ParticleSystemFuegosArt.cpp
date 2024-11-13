#include "ParticleSystemFuegosArt.h"

ParticleSystemFuegosArt::ParticleSystemFuegosArt(Vector3 ori, Vector3 vel, int n, int l)
	: ParticleSystem(ori, vel, n, l)
{
	generator = new FuegosArtificialesGenerator(origen, velMed, numParticles);
}

bool ParticleSystemFuegosArt::update(double t)
{
	//actualiza el tiempo que lleva vivo el sistema

	return ParticleSystem::update(t);
	//return true;
}
