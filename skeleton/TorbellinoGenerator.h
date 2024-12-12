#pragma once
#include "ForceGenerator.h"

class TorbellinoGenerator : public ForceGenerator
{
public:
	TorbellinoGenerator(Vector3 ori) : ForceGenerator(ori) {};
	~TorbellinoGenerator() {};

	Vector3 generateForce(Particle& p) override;

private:

	//Rozamiento
	//Con 10 es suficiente para desviar la bala pequeña
	float k = 1000;
};

