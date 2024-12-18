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
	bool update(double t) override;

	/// Para la gestion de escenas
	virtual void init() override;	//Pone la escena
	virtual void quit() override;	//Quita la escena

protected:
	ForceGenerator* generator = nullptr;
	AnclaFG* ancla;
	double k = 10;
	int rest = 5;

	bool viento = false;

};

