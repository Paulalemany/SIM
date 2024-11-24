#pragma once
#include "Scene.h"
#include "MuelleForeGenerator.h"
#include "MuelleParticleGenerator.h"
#include "VientoGenerator.h"

class AnclaScene : public Scene
{
public:
	AnclaScene();
	~AnclaScene();

	void keyPressed(unsigned char key, const physx::PxTransform& camera) override;

	//Tenemos que hacer nuestro propio update para la fuerza del viento
	void update(double t) override;

protected:
	ForceGenerator* generator = nullptr;
	AnclaFG* ancla;

	bool viento = false;

};

