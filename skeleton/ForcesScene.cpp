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
