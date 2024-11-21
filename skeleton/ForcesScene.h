#pragma once
#include "Scene.h"
#include "ForceGenerator.h"

class ForcesScene : public Scene
{
public:
	ForcesScene();
	~ForcesScene();

	void update(double t)override;

private:
	ForceGenerator* fuerzas = nullptr;
	Particle* e;
};

