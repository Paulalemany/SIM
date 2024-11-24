#pragma once
#include "Scene.h"
#include "MuelleForeGenerator.h"
#include "MuelleParticleGenerator.h"

class MuellesScene : public Scene
{
public:
	MuellesScene();
	~MuellesScene();

	void keyPressed(unsigned char key, const physx::PxTransform& camera) override;

protected:
	ParticleGenerator* generator = nullptr;
	AnclaFG* ancla;

};

