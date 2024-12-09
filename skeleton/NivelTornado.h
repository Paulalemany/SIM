#pragma once
#include "SolidScene.h"
#include "TorbellinoGenerator.h"
#include "ParticleSystemTornado.h"

class NivelTornado : public SolidScene
{
public:
	NivelTornado(PxScene* _scene, PxPhysics* _physics);

	///Input de la escena 
	void update(double t) override;
	//Se va a encargar de generar el viento
	void keyPressed(unsigned char key, const physx::PxTransform& camera) override;


	///Para la gestion de escenas
	void init() override;	//Pone la escena
	void quit() override;	//Quita la escena

private:

	float size = 10;
	Vector3 TPos = { 0,0,0 };
};

