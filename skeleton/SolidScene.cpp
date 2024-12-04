#include "SolidScene.h"

SolidScene::SolidScene(PxScene* _scene, PxPhysics* _physics)
{
	scene = _scene;
	physics = _physics;

	//Generar suelo
	PxRigidStatic* suelo = physics->createRigidStatic(PxTransform({ 0,0,0 }));
	PxShape* shape = CreateShape(PxBoxGeometry(100, 0.1, 100));
	suelo->attachShape(*shape);
	scene->addActor(*suelo);

	//Pintamos el suelo
	RenderItem* item;
	item = new RenderItem(shape, suelo, { 0.05, 0.5, 0.23, 1 });
}

void SolidScene::update(double t)
{

}

void SolidScene::keyPressed(unsigned char key, const physx::PxTransform& camera)
{
}

void SolidScene::init()
{
}

void SolidScene::quit()
{
}
