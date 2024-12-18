#include "Niveles_Menu.h"

Niveles_Menu::Niveles_Menu(PxScene* _scene, PxPhysics* _physics)
	:SolidScene(_scene, _physics)
{
}

void Niveles_Menu::init()
{
	_selector = "___PULSE (EN EL TECLADO) EL NUMERO DEL NIVEL AL QUE DESEA IR___";
	_selector2 = "___CUANDO LO COMPLETES CAMBIARA DE COLOR. COMPLETALOS TODOS!___ ";

	float x = -30;

	for (int i = 0; i < 4; i++) {

		objetos.push_back(new SolidoRigido());
		objetos[i]->CreateStatic(scene, physics, { x, 0, -10 }, { 5, 5, 5 }, colors[i]);

		x += 20.0;
	}
}

void Niveles_Menu::quit()
{
	_selector = " ";
	_selector2 = " ";
	SolidScene::quit();

	if (flag) colors.clear();
}
