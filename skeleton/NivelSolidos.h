#pragma once
#include "SolidScene.h"

extern std::string _nivelSolidos;
extern std::string _explicacionContinuar;
class NivelSolidos : public SolidScene
{
public:
	NivelSolidos(PxScene* _scene, PxPhysics* _physics);

	bool update(double t) override;

	void shoot(Vector3 pos) override;

	void init() override;	//Pone la escena
	void quit() override;	//Quita la escena


private:

	SolidoRigido* solidBullet = nullptr;
	Particle* solidtarget = nullptr;
	const Vector3 oriSolid = { -30, 0, 0 };

};

