#include "ParticleSystemViento.h"

ParticleSystemViento::ParticleSystemViento(Vector3 ori, Vector3 vel, int n, int l)
	:ParticleSystem(ori, vel, n, l)
{
	//generator = new HumoGenerator(origen, velMed, numParticles);
	generator = new VientoParticleGenerator(origen, velMed, numParticles);
}

bool ParticleSystemViento::update(double t)
{
	//Puede que haya que ponerle aqui el booleano
	return ParticleSystem::update(t);
}
