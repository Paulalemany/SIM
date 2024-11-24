#pragma once
#include "Scene.h"
#include "MuelleForeGenerator.h"
#include "MuelleParticleGenerator.h"

class AnclaScene : public Scene
{
public:
	AnclaScene();
	~AnclaScene();

protected:
	ParticleGenerator* generator = nullptr;
	AnclaFG* ancla;

};

