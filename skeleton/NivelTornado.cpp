#include "NivelTornado.h"
#include <iostream>

NivelTornado::NivelTornado(PxScene* _scene, PxPhysics* _physics)
	:SolidScene(_scene, _physics)
{
	//Añadimos las fuerzas
	fuerzas.push_back(new TorbellinoGenerator(TPos));
	fuerzas[0]->setRadio(size);

	//Cuando esté hecho habrá que ponerle el sistema de particulas
	sistemas.push_back(new ParticleSystemTornado(TPos, { 0,0, 0 }, 100, 50000, size));
}

void NivelTornado::init()
{
	///Creamos el nivel

	target = new SolidoRigido();
	target->CreateStatic(scene, physics, { 20, 0, 0 }, { 2,2,2 }, { 0,0,0,1 });
	objetos.push_back(target);

	canon = new Particle({ -20, 0, 0 });
	canon->setTam({ 0.5, 1, 0.5 }, 1);

	active = true;

	Scene::init();
}

void NivelTornado::quit()
{
	SolidScene::quit();
}
