#pragma once
#include "Scene.h"

using namespace physx;
class SolidScene : public Scene
{
public:

	SolidScene(PxScene* _scene, PxPhysics* _physics);

	void update(double t) override;

	///Input de la escena
	void keyPressed(unsigned char key, const physx::PxTransform& camera) override;

	/// Para la gestion de escenas
	void init() override;	//Pone la escena
	void quit() override;	//Quita la escena

private:
	PxScene* scene = NULL;
	PxPhysics* physics = NULL;

};

