#pragma once
#include "ParticleSystem.h"
#include "BrillitosParticleGenerator.h"

class ParticleSystemBrillitos : public ParticleSystem
{
public:
	ParticleSystemBrillitos(Vector3 ori, Vector3 vel, int n, int l);
	bool update(double t) override;

private:
	std::vector<Particle*> pAux;
};

