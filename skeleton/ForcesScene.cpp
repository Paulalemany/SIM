#include "ForcesScene.h"

ForcesScene::ForcesScene()
{
	fuerzas = new ForceGenerator(Vector3(-100,0,-50));

	particulas.push_back(new Proyectil({ -200, 0, -50 }, { 50, 0, 0 }, { 2,0,0 }, 0.5));

	//for (auto p : particulas) p->setLiveTime(5);
}

ForcesScene::~ForcesScene()
{
}

void ForcesScene::update(double t)
{

	for (auto p : particulas) {

		//Si las particulas estan dentro del radio de accion
		if (fuerzas->onZone(p->getPosition())) p->addForce(fuerzas->generateForce(*p));
		p->restLiveTime(t);
		p->update(t);
		
	}

	//fuerzas->update(t);
}
