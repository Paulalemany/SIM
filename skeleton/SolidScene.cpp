#include "SolidScene.h"

SolidScene::SolidScene(PxScene* _scene, PxPhysics* _physics)
{
	scene = _scene;
	physics = _physics;

	//Generar suelo
	//Se pueden crear y poner diferentes materiales
	//PxPhysics::createMaterial(staticFriction, dynamicFriction, restitution);
	//gMaterial = gPhysics->createMaterial(0.5f, 0.5f, 0.6f);

	mat = physics->createMaterial(1, 1, 0);

	/*SolidoRigido* suelo = new SolidoRigido();
	suelo->CreateStatic(scene, physics,
		{ 0,0,0 }, { 100, 0.1, 100 }, { 0.05, 0.5, 0.23, 1 });

	objetos.push_back(suelo);*/

	//Vamos a probar lo de los momentos de inercia
	/*SolidoRigido* solido1 = new SolidoRigido(scene, physics, 
		{ -70, 200, -70 }, { 0,5,0 }, { 0,0,0 }, { 5, 5, 5 }, 0.15, { 1,0,0,1 });
	solido1->setInertia();

	objetos.push_back(solido1);

	SolidoRigido* solido2 = new SolidoRigido(scene, physics,
		{ 0, 200, 0 }, { 0,10,0 }, { 5,0,0 }, { 5 ,5 ,5 }, 100, { 1,0,0,1 });

	objetos.push_back(solido2);*/

	///Vamos a dibujar los ejes
	SolidoRigido* O = new SolidoRigido();
	O->CreateStatic(scene, physics, { 0,0,0 }, { 0.5,0.5,0.5 }, { 1,1,1,1 });

	SolidoRigido* X = new SolidoRigido();
	X->CreateStatic(scene, physics, { 1,0,0 }, { 0.5,0.5,0.5 }, { 1,0,0,1});

	SolidoRigido* Y = new SolidoRigido();
	Y->CreateStatic(scene, physics, { 0,1,0 }, { 0.5,0.5,0.5 }, { 0,1,0,1 });
	

	//Voy a utilizarlo de cañon
	SolidoRigido* P = new SolidoRigido();
	P->CreateStatic(scene, physics, { -20,0,0 }, { 0.5,0.5,0.5 }, { 0,0,0,1 });
}

void SolidScene::update(double t)
{

}

void SolidScene::keyPressed(unsigned char key, const physx::PxTransform& camera)
{
}

void SolidScene::init()
{
	RegisterRenderItem(item);
}

void SolidScene::quit()
{
	//Vamos a testear los cambios de escena

	//DeregisterRenderItem(item);
}
