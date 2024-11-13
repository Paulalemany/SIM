#pragma once
#include "ParticleSystem.h"

class ParticleSystemFuegosArt : public ParticleSystem
{
public:

	ParticleSystemFuegosArt(Vector3 ori, Vector3 vel, int n, int l);
	bool update(double t) override;

private:

};

