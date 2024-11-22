#pragma once
#include "ParticleGenerator.h"

class MuelleParticleGenerator : public ParticleGenerator
{
public:
	MuelleParticleGenerator(Vector3 o, Vector3 vel, int np);
	~MuelleParticleGenerator();

	std::vector<Proyectil*> CreateParticles(int actParticles, int maxParticles) override;
	std::vector<Particle*> CreateParticles();
};

