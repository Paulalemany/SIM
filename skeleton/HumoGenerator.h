#pragma once
#include "ParticleGenerator.h"

class HumoGenerator : public ParticleGenerator
{
public:

	HumoGenerator(Vector3 o, Vector3 vel, int np);

	std::vector<Proyectil*> CreateParticles(int actParticles, int maxParticles) override;
};

