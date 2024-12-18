#include "Start_Menu.h"
#include <iostream>

Start_Menu::Start_Menu(PxScene* _scene, PxPhysics* _physics)
	:SolidScene(_scene, _physics)
{
	sistemas.push_back(new ParticleSystemBrillitos({ 0,0,0 }, { 0,0,0 }, 500, 1));
}

void Start_Menu::init()
{
	if (!win) {
		//textos
		_start = "___PULSA 'ENTER' PARA EMPEZAR___";
		_intro = "___PRACTICA TUS HABILIDADES DE TIRO EN LOS SIGUIENTES NIVELES___";
		_balas = "___TIENES 3 TIPOS DE BALAS:___";
		_ExplicacionS = "___PULSANDO 'S' TU BALA SE VUELVE CHIQUITA Y PESA MENOS____________";
		_ExplicacionM = "___PULSANDO 'M' TU BALA SE VUELVE MEDIANA Y TIENE PESO ESTANDAR___";
		_ExplicacionL = "___PULSANDO 'L' TU BALA SE VUELVE GRANDE Y SU PESO ES MAYOR________";

		//Fondo de decoracion
		SolidoRigido* s = new SolidoRigido();
		s->CreateStatic(scene, physics, { -1,-8,0 }, { 5,10,5 }, { 1, 1, 1 ,1 });
		s->changeShape(1);
		objetos.push_back(s);
	}
	else {
		
		_fin = "___FELICIDADES!!!! GRACIAS POR JUGAR___";
	}
	

	active = true;
	Scene::init();
}

void Start_Menu::quit()
{
	SolidScene::quit();
	_start = " ";
	_intro = " ";
	_balas = " ";
	_ExplicacionS = " ";
	_ExplicacionM = " ";
	_ExplicacionL = " ";
	_fin = " ";
	active = false;
}
