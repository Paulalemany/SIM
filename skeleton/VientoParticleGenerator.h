#pragma once
#include  "ParticleGenerator.h"

class VientoParticleGenerator : public ParticleGenerator
{
public:

	VientoParticleGenerator(Vector3 o, Vector3 vel, int np);

	std::vector<Proyectil*> CreateParticles(int actParticles, int maxParticles) override;

};

