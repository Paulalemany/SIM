#pragma once
#include "SolidScene.h"
#include "FlotacionForce.h"

class NivelFlotacion : public SolidScene
{
public:
	NivelFlotacion(PxScene* _scene, PxPhysics* _physics);

	///Input concreto de la escena 
	//(A lo mejor nos interesa generar viento en momentos concretos o algo asi)
	void keyPressed(unsigned char key, const physx::PxTransform& camera) override;

	/// Para la gestion de escenas
	void init() override;	//Pone la escena
	void quit() override;	//Quita la escena

private:

};

