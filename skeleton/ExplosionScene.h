#pragma once
#include "Scene.h"

class ExplosionScene : public Scene
{
public:
	ExplosionScene();
	~ExplosionScene();

	void update(double t) override;
};

