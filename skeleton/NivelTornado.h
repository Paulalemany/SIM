#pragma once
#include "SolidScene.h"
#include "TorbellinoGenerator.h"
#include "ParticleSystemTornado.h"

extern std::string _start;

class NivelTornado : public SolidScene
{
public:
	NivelTornado(PxScene* _scene, PxPhysics* _physics);

	void update(double t) override;

	///Para la gestion de escenas
	void init() override;	//Pone la escena
	void quit() override;	//Quita la escena

private:

	float size = 50;
	Vector3 TPos = { 0,0,0 };
};

