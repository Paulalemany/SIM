#pragma once
#include "ParticleSystem.h"

class ParticleSystemFuente : public ParticleSystem
{
public: 
	ParticleSystemFuente(Vector3 ori, Vector3 vel, int n, int l);
	bool update(double t) override;

private:

};

