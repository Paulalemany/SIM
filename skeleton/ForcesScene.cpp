#include "ForcesScene.h"

ForcesScene::ForcesScene()
{
	fuerzas.push_back(new ForceGenerator(Vector3(-100,0,-50)));


	particulas.push_back(new Proyectil({ -150, 0, -50 }, { 60, 0, -10 }, { 2,0,2 }, 0.5));

	for (auto p : particulas) {
		p->setLiveTime(500);
		p->setMasa(0.1);
	}
}

ForcesScene::~ForcesScene()
{
}

void ForcesScene::update(double t)
{

	for (auto p : particulas) {

		//Si las particulas estan dentro del radio de accion
		for (auto f : fuerzas)
		if (f->onZone(p->getPosition())) p->addForce(f->generateForce(*p));
	}

	Scene::update(t);
}
