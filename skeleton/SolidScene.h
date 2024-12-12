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
	void keyPressed(unsigned char key, const physx::PxTransform& camera) override;
	virtual void shoot(Vector3 pos);

	/// Para la gestion de escenas
	virtual void init() override;	//Pone la escena
	virtual void quit() override;	//Quita la escena

	//Iria bien un metodo de generar escenario o algo asi
	//Podria ser un metodo privado perfectamente

protected:
	PxScene* scene = NULL;
	PxPhysics* physics = NULL;
	PxMaterial* mat = NULL;

	//Guardamos todos los objetos en un vector?
	vector<SolidoRigido*> objetos;

	///Dedicado al gameplay
	SolidoRigido* target = nullptr;
	Particle* canon = nullptr;
	Particle* bullet = nullptr;

	//Particularidades de la bala
	//De forma predeterminada sera la mediana

	const float SbulletMasa = 10;
	const float MbulletMasa = 1000;
	const float LbulletMasa = 10000;

	const float SbulletTam = 0.5;
	const float MbulletTam = 1;
	const float LbulletTam = 2;

	const Vector4 SbulletCol = { 0, 0, 1, 1 };
	const Vector4 MbulletCol = { 1, 0, 0, 1 };
	const Vector4 LbulletCol = { 0, 1, 0, 1 };

	Vector4 bulletColor = MbulletCol;
	float bulletMasa = MbulletMasa;
	float bulletTam = MbulletTam;

};

