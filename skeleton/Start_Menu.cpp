#include "Start_Menu.h"

Start_Menu::Start_Menu(PxScene* _scene, PxPhysics* _physics)
	:SolidScene(_scene, _physics)
{
	sistemas.push_back(new ParticleSystemBrillitos({ 0,0,0 }, { 0,0,0 }, 500, 1));
}

void Start_Menu::update(double t)
{
	SolidScene::update(t);
}

void Start_Menu::keyPressed(unsigned char key, const physx::PxTransform& camera)
{
}

void Start_Menu::init()
{
	_start = "___PULSA 'ENTER' PARA EMPEZAR___";

	//Fondo de decoracion
	SolidoRigido* s = new SolidoRigido();
	s->CreateStatic(scene, physics, { -1,5,0 }, { 5,10,5 }, { 0.96, 0.85, 0.88 ,1 });
	s->changeShape(1);
	objetos.push_back(s);

	//ponemos como si fueran brillitos al rededor

	SolidScene::init();
	active = true;
}

void Start_Menu::quit()
{
	SolidScene::quit();
	_start = " ";
	active = false;
}
