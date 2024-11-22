#pragma once
#include "ForceGenerator.h"

class MuelleForeGenerator : public ForceGenerator
{
public:
	MuelleForeGenerator(Vector3 ori, double _k, double rl, Particle* p);
	~MuelleForeGenerator() {}

	virtual void updateForce(Particle* p);

	void setK(double _k) { k = _k; }

protected:
	double k = 0;
	double resting_length;
	Particle* par;
};

