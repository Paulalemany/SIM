#pragma once
#include "ParticleGenerator.h"


class FuenteGenerator : public ParticleGenerator
{
public:
	FuenteGenerator(Vector3 o, Vector3 vel, int np);

	//Habr� que pasarle el numero de particulas que hay 
	// y el numero maximo de particulas que puede haber
	std::vector<Proyectil*> CreateParticles(int actParticles, int maxParticles) override;

};

