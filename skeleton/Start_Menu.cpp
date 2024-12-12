#include "Start_Menu.h"

Start_Menu::Start_Menu(PxScene* _scene, PxPhysics* _physics)
	:SolidScene(_scene, _physics)
{
}

void Start_Menu::update(double t)
{
}

void Start_Menu::keyPressed(unsigned char key, const physx::PxTransform& camera)
{
}

void Start_Menu::init()
{
	_start = "___PULSA 'ENTER' PARA EMPEZAR___";

	//Quiero probar formas de solidos rigidos

	//Testeando
	SolidoRigido* s = new SolidoRigido();

	s->CreateStatic(scene, physics, { 0,0,0 }, { 5,5,5 }, { 1,1,1,1 });
	s->changeShape(0);
}

void Start_Menu::quit()
{
	_start = " ";
}
