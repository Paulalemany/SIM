#include "VientoScene.h"

VientoScene::VientoScene()
{
	//Añadimos las fuerzas
	fuerzas.push_back(new VientoGenerator(Vector3{-50,0,-20}, Vector3(20, 0, -20)));
	fuerzas[0]->setRadio(100);	//Hacemos que la zona sea grande
}

VientoScene::~VientoScene()
{
}

void VientoScene::update(double t)
{
	//Vamos generando particulas para que se lleve el viento
	if (particulas.size() < 5) {
		Proyectil* p = new Proyectil({ -50, 0, -20 }, { 0,0,0 }, { 0,0,0 }, 0.5);
		p->setLiveTime(500);
		p->setMasa(0.1);
		particulas.push_back(p);
	}

	Scene::update(t);
}
