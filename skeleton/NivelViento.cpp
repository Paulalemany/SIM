#include "NivelViento.h"
#include <iostream>

NivelViento::NivelViento(PxScene* _scene, PxPhysics* _physics)
	:SolidScene(_scene, _physics)
{

	//A�adimos la fuerza del viento
	fuerzas.push_back(new VientoGenerator({ 0,0,0 }, { -10, 10, 0 }));	//Ya veremos cuanta fuerza le ponemos al viento
}

void NivelViento::update(double t)
{
	//La base es igual que en la padre pero las fuerzas hay que cambiarlas
	if (bullet != nullptr) {
		bullet->update(t);

		//Comprobamos si ha llegado al target
		if (target->inBoundingBox(bullet->getPosition())) cout << " Buah como mola el viento";
		//Ponemos las fuerzas pero solo si esta activada
		if (viento) {
			fuerzas[0]->update(t);
			if (fuerzas[0]->onZone(bullet->getPosition())) bullet->addForce(fuerzas[0]->generateForce(*bullet));
		}

		//Comprobamos las colisiones con el resto de sitios
		for (auto o : objetos)
			if (o->inBoundingBox(bullet->getPosition()))
				bullet->setVelocidad({ 0,0,0 });	//Esto si me da tiempo cambiarlo porque seria increible ponerle efectos
	}

	Scene::update(t);
}

void NivelViento::keyPressed(unsigned char key, const physx::PxTransform& camera)
{
	SolidScene::keyPressed(key, camera);	//Lo que hacemos es ademas de lo que se hace en la clase padre

	//Con la v activamos y desactivamos el viento 
	if (key == 'v') viento = !viento;
}

void NivelViento::init()
{
	Scene::init();

	//creamos la escena
	//Target del nivel
	target->CreateStatic(scene, physics, { 20, -5, -0.5 }, { 2, 2, 2 }, { 0, 0, 0, 1 });
}

void NivelViento::quit()
{
	Scene::quit();
}
