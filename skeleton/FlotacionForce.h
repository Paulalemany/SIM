#pragma once
#include "ForceGenerator.h"

class FlotacionForce : public ForceGenerator
{
public:
	FlotacionForce(Vector3 ori, float _h, float _v, float _d);
	~FlotacionForce();

	Vector3 generateForce(Particle& p) override;

private:
	float altura;
	float volumen;
	float densidad;
	float gravedad = 9.8;

	Particle* particulaLiquida;
};

