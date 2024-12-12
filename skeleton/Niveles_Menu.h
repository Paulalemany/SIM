#pragma once
#include "SolidScene.h"

extern std::string _selector;
extern std::string _selector2;
class Niveles_Menu : public SolidScene
{
public:
	Niveles_Menu(PxScene* _scene, PxPhysics* _physics);

	///Para la gestion de escenas
	void init() override;	//Pone la escena
	void quit() override;	//Quita la escena

private:
	SolidoRigido* N1 = nullptr;
	SolidoRigido* N2 = nullptr;
	SolidoRigido* N3 = nullptr;
};

