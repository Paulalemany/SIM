#include "Niveles_Menu.h"

Niveles_Menu::Niveles_Menu(PxScene* _scene, PxPhysics* _physics)
	:SolidScene(_scene, _physics)
{
}

void Niveles_Menu::init()
{
	_selector = "___PULSE (EN EL TECLADO) EL NUMERO DEL NIVEL AL QUE DESEA IR___";
	_selector2 = "___CUANDO LO COMPLETES CAMBIARA DE COLOR. COMPLETALOS TODOS!___ ";

	N1 = new SolidoRigido();
	N1->CreateStatic(scene, physics, { -40, 0, -10 }, { 10, 10, 10 }, { 0.85, 0.69, 0.97, 1 });
	objetos.push_back(N1);
	
	N2 = new SolidoRigido();
	N2->CreateStatic(scene, physics, { 0, 0, -10 }, { 10, 10, 10 }, { 0.85, 0.69, 0.97, 1 });
	objetos.push_back(N2);
	
	N3 = new SolidoRigido();
	N3->CreateStatic(scene, physics, { 40, 0, -10 }, { 10, 10, 10 }, { 0.85, 0.69, 0.97, 1 });
	objetos.push_back(N3);
}

void Niveles_Menu::quit()
{
	_selector = " ";
	_selector2 = " ";
	SolidScene::quit();
}
