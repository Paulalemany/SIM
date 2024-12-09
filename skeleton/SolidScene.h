#pragma once
#include "Scene.h"
#include "SolidoRigido.h"

using namespace physx;
class SolidScene : public Scene
{
public:

	SolidScene(PxScene* _scene, PxPhysics* _physics);
	~SolidScene();

	virtual void update(double t) override;

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
	Particle* bullet = nullptr;

	//Particularidades de la bala
	//De forma predeterminada sera la mediana
	Vector4 bulletColor = { 1,0,0,1 };
	float bulletMasa = 5000;
	float bulletTam = 1;

};

