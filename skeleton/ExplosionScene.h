#pragma once
#include "Scene.h"
#include "ExplosionGenerator.h"

class ExplosionScene : public Scene
{
public:
	ExplosionScene();
	~ExplosionScene();

	void update(double t) override;

private:
	float pi = 3.1415;
	int alpha = 0, beta = 0, delta = 0;
	int anglesum = 10;
};

