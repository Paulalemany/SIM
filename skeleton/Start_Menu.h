#pragma once
#include "SolidScene.h"

extern std::string _start;
class Start_Menu : public SolidScene
{
public:
	Start_Menu(PxScene* _scene, PxPhysics* _physics);

	///Input de la escena 
	void update(double t) override;
	
	void keyPressed(unsigned char key, const physx::PxTransform& camera) override;


	///Para la gestion de escenas
	void init() override;	//Pone la escena
	void quit() override;	//Quita la escena
};

