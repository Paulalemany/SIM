#pragma once
#include "Scene.h"
#include "SolidoRigido.h"

using namespace physx;
class SolidScene : public Scene
{
public:

	SolidScene(PxScene* _scene, PxPhysics* _physics);
	~SolidScene();

	virtual bool update(double t) override;

	///Input de la escena
	virtual void keyPressed(unsigned char key, const physx::PxTransform& camera) override;
	virtual void shoot(Vector3 pos);

	/// Para la gestion de escenas
	virtual void init() override;	//Pone la escena
	virtual void quit() override;	//Quita la escena

	virtual void setColors(vector<Vector4> c) { colors = c; }
	virtual void setWin(bool b) {}
	virtual bool getWin() { return false; }


protected:
	PxScene* scene = NULL;
	PxPhysics* physics = NULL;
	PxMaterial* mat = NULL;

	//Guardamos todos los objetos en un vector?
	vector<SolidoRigido*> objetos;
	vector<Vector4> colors;

	///Dedicado al gameplay
	SolidoRigido* target = nullptr;
	Particle* canon = nullptr;
	Particle* bullet = nullptr;

	//Particularidades de la bala
	//De forma predeterminada sera la mediana

	//masa
	const float SbulletMasa = 10;
	const float MbulletMasa = 1000;
	const float LbulletMasa = 10000;

	//radio
	const float SbulletTam = 0.5;
	const float MbulletTam = 1;
	const float LbulletTam = 2;

	const Vector4 SbulletCol = { 0, 0, 1, 1 };
	const Vector4 MbulletCol = { 1, 0, 0, 1 };
	const Vector4 LbulletCol = { 0, 1, 0, 1 };

	Vector4 bulletColor = MbulletCol;
	float bulletMasa = MbulletMasa;
	float bulletTam = MbulletTam;

	const Vector3 ori = { -20, 0, 0 };

};

