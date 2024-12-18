#include "NivelSolidos.h"

#include <iostream>

NivelSolidos::NivelSolidos(PxScene* _scene, PxPhysics* _physics)
	:SolidScene(_scene, _physics)
{
}

bool NivelSolidos::update(double t)
{
	///Particulas del gameplay
	if (solidBullet != nullptr) {

		//Aqui simplemente poner la condicion de victoria
		if (solidtarget->inBoundingBox(solidBullet->getPosition()))
			return true;
	}

	return false;

}

void NivelSolidos::shoot(Vector3 pos)
{
	if (solidBullet != nullptr) solidBullet->~SolidoRigido();	//Solo queremos una bala en escena

	//La direccion es el vector que hay entre el punto pos y el origen
	Vector3 dir = (pos - ori).getNormalized();

	//Esta vez la bala es un solido dinamico
	solidBullet = new SolidoRigido(scene, physics,
		{ oriSolid.x, oriSolid.y, oriSolid.z }, dir * 60, { 0,0,0 }, { bulletTam, bulletTam, bulletTam }, 
		SolidoRigido::ESFERA, bulletMasa, bulletColor);
}

void NivelSolidos::init()
{
	if (flag) {
		//Target del nivel
		solidtarget = new Particle({ 15, 0, 0 });
		solidtarget->setTam({ 2,2,2 }, 1);


		//Ponemos el cañon
		canon = new Particle(oriSolid);
		canon->setTam({ 0.5, 1, 0.5 }, 1);

		//Vamos a poner un suelo a ver que pasa
		SolidoRigido* suelo = new SolidoRigido();
		suelo->CreateStatic(scene, physics, { -10,-20,0 }, { 5, 1, 1 }, { 1,1,1,1 });
		objetos.push_back(suelo);

		//Pared derecha
		SolidoRigido* paredDer = new SolidoRigido();
		paredDer->CreateStatic(scene, physics, { 5, -5, 0 }, { 1, 7, 1 }, { 1,1,1,1 });
		objetos.push_back(paredDer);

		//Pared izquierda
		SolidoRigido* paredIzq = new SolidoRigido();
		paredIzq->CreateStatic(scene, physics, { -10, 5, 0 }, { 1, 7, 1 }, { 1,1,1,1 });
		objetos.push_back(paredIzq);
	}
	else {
		_nivelSolidos = "___Aqui las paredes rebotan___";
		_explicacionContinuar = "___Pulse el mismo numero para continuar___";
	}
	
}

void NivelSolidos::quit()
{
	_nivelSolidos = "";
	_explicacionContinuar = "";
	if (solidtarget != nullptr) solidtarget->~Particle();
	if (solidBullet != nullptr) solidBullet->~SolidoRigido();
	SolidScene::quit();
}