#pragma once
#include "ParticleGenerator.h"

class TornadoParticleGenerator : public ParticleGenerator
{
public:
	TornadoParticleGenerator(Vector3 o, Vector3 vel, int np, float r);

	std::vector<Proyectil*> CreateParticles(int actParticles, int maxParticles) override;
	std::vector<Particle*> CreateStaticParticles(int actParticles, int maxParticles) override;

private:
	float radio = 0;	//Para saber donde generar el origen
};

