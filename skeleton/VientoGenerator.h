#pragma once
#include "ForceGenerator.h"

class VientoGenerator : public ForceGenerator
{
public:

	VientoGenerator(Vector3 ori, Vector3 v);

	~VientoGenerator();

	Vector3 generateForce(Particle& p) override;

protected:

	//Coeficiente de rozamiento
	float k1 = 10;
	Vector3 k2 = { 0,0,0 };

	//Velocidad del viento
	Vector3 viento = { 0,0,0 };

};

