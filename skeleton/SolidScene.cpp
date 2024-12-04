#include "SolidScene.h"

SolidScene::SolidScene(PxScene* _scene, PxPhysics* _physics)
{
	scene = _scene;
	physics = _physics;

	//Generar suelo
	suelo = physics->createRigidStatic(PxTransform({ 0,0,0 }));
	PxShape* shape = CreateShape(PxBoxGeometry(100, 0.1, 100));
	suelo->attachShape(*shape);
	scene->addActor(*suelo);

	//Pintamos el suelo
	item = new RenderItem(shape, suelo, { 0.05, 0.5, 0.23, 1 });

	//Generamos actores dinamicos
	PxRigidDynamic* new_solid;
	new_solid = physics->createRigidDynamic(PxTransform({ -70, 200, -70 }));
	new_solid->setLinearVelocity({ 0,5,0 });
	new_solid->setAngularVelocity({ 0,0,0 });
	PxShape* shape_ad = CreateShape(PxBoxGeometry(5, 5, 5));
	new_solid->attachShape(*shape_ad);

	//Hay que definir tambien la distribucion de masas en actores dinamicos
	PxRigidBodyExt::updateMassAndInertia(*new_solid, 0.15);	//El 0.15 es la densidad kg/m3
	scene->addActor(*new_solid);

	RenderItem* item2;
	item2 = new RenderItem(shape_ad, new_solid, { 1,0,0,1 });

	//Generamos actores dinamicos
	PxRigidDynamic* solid;
	solid = physics->createRigidDynamic(PxTransform({ 0, 200, 0 }));
	solid->setLinearVelocity({ 0,5,0 });
	solid->setAngularVelocity({ 0,0,0 });
	PxShape* shape2 = CreateShape(PxBoxGeometry(5, 5, 5));
	solid->attachShape(*shape2);

	//Hay que definir tambien la distribucion de masas en actores dinamicos
	PxRigidBodyExt::updateMassAndInertia(*solid, 10);	//El 0.15 es la densidad kg/m3
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
