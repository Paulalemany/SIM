#include "Niveles_Menu.h"

Niveles_Menu::Niveles_Menu(PxScene* _scene, PxPhysics* _physics)
	:SolidScene(_scene, _physics)
{
}

void Niveles_Menu::init()
{
	_selector = "___PULSE (EN EL TECLADO) EL NUMERO DEL NIVEL AL QUE DESEA IR___";
	_selector2 = "___CUANDO LO COMPLETES CAMBIARA DE COLOR. COMPLETALOS TODOS!___ ";

	float x = -40;

	for (int i = 0; i < colors.size(); i++) {

		objetos.push_back(new SolidoRigido());
		objetos[i]->CreateStatic(scene, physics, { x, 0, -10 }, { 10, 10, 10 }, colors[i]);

		x += 40.0;
	}
}

void Niveles_Menu::quit()
{
	_selector = " ";
	_selector2 = " ";
	SolidScene::quit();
}
