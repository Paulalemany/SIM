#pragma once
#include "ParticleGenerator.h"

class BrillitosParticleGenerator : public ParticleGenerator
{
public:
	BrillitosParticleGenerator(Vector3 o, Vector3 vel, int np);

	std::vector<Proyectil*> CreateParticles(int actParticles, int maxParticles) override;
	std::vector<Particle*> CreateStaticParticles(int actParticles, int maxParticles) override;
};

