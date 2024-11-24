#pragma once
#include "ForceGenerator.h"

class MuelleForeGenerator : public ForceGenerator
{
public:
	MuelleForeGenerator(Vector3 ori, double _k, double rl, Particle* p);
	~MuelleForeGenerator() {}

	Vector3 generateForce(Particle& p) override;

	void setK(double _k) { k = _k; }

protected:
	double k = 0;
	double resting_length;
	Particle* par;
};

