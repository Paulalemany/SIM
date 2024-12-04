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
	suelo = physics->createRigidStatic(PxTransform({ 0,0,0 }));
	PxShape* shape = CreateShape(PxBoxGeometry(100, 0.1, 100));
	suelo->attachShape(*shape);
	scene->addActor(*suelo);

	//Pintamos el suelo
	item = new RenderItem(shape, suelo, { 0.05, 0.5, 0.23, 1 });

	SolidoRigido* solido = new SolidoRigido(scene, physics, 
		{ -70, 200, -70 }, { 0,5,0 }, { 0,0,0 }, { 5, 5, 5 }, 0.15, { 1,0,0,1 });

	//Generamos actores dinamicos
	PxRigidDynamic* solid;
	solid = physics->createRigidDynamic(PxTransform({ 0, 200, 0 }));
	solid->setLinearVelocity({ 0,5,0 });
	solid->setAngularVelocity({ 0,0,0 });
	PxShape* shape2 = CreateShape(PxBoxGeometry(5, 5, 5));
	solid->attachShape(*shape2);

	//Hay que definir tambien la distribucion de masas en actores dinamicos
	PxRigidBodyExt::updateMassAndInertia(*solid, 100);	//El 0.15 es la densidad kg/m3
	scene->addActor(*solid);

	RenderItem* item3;
	item3 = new RenderItem(shape2, solid, { 1,0,0,1 });
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

	DeregisterRenderItem(item);
}
