#pragma once
#include "ParticleGenerator.h"
#include <random>

class FuenteGenerator : public ParticleGenerator
{
public:
	FuenteGenerator(Vector3 o, Vector3 vel, int np);

	//Habrá que pasarle el numero de particulas que hay 
	// y el numero maximo de particulas que puede haber
	std::vector<Proyectil*> CreateParticles(int actParticles, int maxParticles);

private:

	std::default_random_engine generator;
};

