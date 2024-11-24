#pragma once
#include "Scene.h"
#include "MuelleForeGenerator.h"
#include "MuelleParticleGenerator.h"

class MuellesScene : public Scene
{
public:
	MuellesScene();
	~MuellesScene();

	void update(double t)override;

protected:
	ParticleGenerator* generator = nullptr;
	AnclaFG* ancla;

};

