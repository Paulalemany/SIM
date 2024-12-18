#pragma once
#include "ForceGenerator.h"

class ExplosionGenerator : public ForceGenerator
{
public:

	ExplosionGenerator(Vector3 ori, float pot) : ForceGenerator(ori) { time = 0; k = pot; }

	~ExplosionGenerator() {};

	void startGenerate() {
		time = 0;
	};

	void update(double t) override;

	Vector3 generateForce(Particle& p) override;

private:

	float k = 100;	//Fuerza de la explosion
	const float q = 10;	//Constante de tiempo de la explosion
	const float vel = 30;	//Velocidad de la expansion de la explosion
	float time = 0;
};

