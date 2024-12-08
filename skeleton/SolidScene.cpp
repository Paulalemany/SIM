#include "SolidScene.h"

SolidScene::SolidScene(PxScene* _scene, PxPhysics* _physics)
{
	scene = _scene;
	physics = _physics;

	mat = physics->createMaterial(1, 1, 0);

	init();	
	//Con este metodo inicializamos la escena para que se reinicie cada vez que entremos al nivel
}

void SolidScene::update(double t)
{

}

void SolidScene::keyPressed(unsigned char key, const physx::PxTransform& camera)
{
}

void SolidScene::init()
{
	///Vamos a dibujar los ejes
	SolidoRigido* O = new SolidoRigido();
	O->CreateStatic(scene, physics, { 0,0,0 }, { 0.5,0.5,0.5 }, { 1,1,1,1 });
	objetos.push_back(O);

	SolidoRigido* X = new SolidoRigido();
	X->CreateStatic(scene, physics, { 1,0,0 }, { 0.5,0.5,0.5 }, { 1,0,0,1 });
	objetos.push_back(X);

	SolidoRigido* Y = new SolidoRigido();
	Y->CreateStatic(scene, physics, { 0,1,0 }, { 0.5,0.5,0.5 }, { 0,1,0,1 });
	objetos.push_back(Y);


	//Voy a utilizarlo de cañon
	SolidoRigido* P = new SolidoRigido();
	P->CreateStatic(scene, physics, { -20,0,0 }, { 0.5,0.5,0.5 }, { 0,0,0,1 });
	objetos.push_back(P);
}

void SolidScene::quit()
{
	//Esto seria por ahora eliminar todos los solidoRigidos del vector
	for (auto e : objetos) e->~SolidoRigido();
	
}
