#pragma once
#include "SolidScene.h"
#include "VientoGenerator.h"

class NivelViento : public SolidScene
{
public:
	NivelViento(PxScene* _scene, PxPhysics* _physics);

	///Input de la escena 
	void update(double t) override;
	//Se va a encargar de generar el viento
	void keyPressed(unsigned char key, const physx::PxTransform& camera) override;


	///Para la gestion de escenas
	void init() override;	//Pone la escena
	void quit() override;	//Quita la escena

private:

	bool viento = false;	//Para controlar cuando se activa el viento

};
