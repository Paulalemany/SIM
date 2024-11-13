#pragma once
#include "ParticleSystem.h"

class ParticleSystemHumo : public ParticleSystem
{
public:
	ParticleSystemHumo(Vector3 ori, Vector3 vel, int n, int l);

	bool update(double t) override;
private:

};

