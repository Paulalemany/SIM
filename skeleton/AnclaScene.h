#pragma once
#include "Scene.h"
#include "MuelleForeGenerator.h"
#include "MuelleParticleGenerator.h"

class AnclaScene : public Scene
{
public:
	AnclaScene();
	~AnclaScene();

	void keyPressed(unsigned char key, const physx::PxTransform& camera) override;

protected:
	ParticleGenerator* generator = nullptr;
	AnclaFG* ancla;

};

