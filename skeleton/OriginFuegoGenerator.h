#pragma once
#include "ParticleGenerator.h"

class OriginFuegoGenerator : public ParticleGenerator
{
public:

	OriginFuegoGenerator(Vector3 o, Vector3 vel, int np);

	std::vector<Proyectil*> CreateParticles(int actParticles, int maxParticles) override;
};

