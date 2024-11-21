#include "ForcesScene.h"

ForcesScene::ForcesScene()
{
	fuerzas = new ForceGenerator(Vector3(-150,0,-100));

	particulas.push_back(new Proyectil({ 0, 0, 0 }, { 0, 10, 0 }, { 0,1,0 }, 0.5));

	//e = new Particle({ 0,0,0 }, { 0,10,0 }, { 0,0,0,1 });

	//for (auto p : particulas) p->setLiveTime(5);
}

ForcesScene::~ForcesScene()
{
}

void ForcesScene::update(double t)
{
	//e->update(t);
	particulas[0]->update(t);

	//for (auto p : particulas) {

	//	//Si las particulas estan dentro del radio de accion
	//	//if (fuerzas->onZone(p->getPosition())) p->addForce(fuerzas->generateForce(*p));
	//	p->restLiveTime(t);
	//	p->update(t);
	//	
	//}

	//fuerzas->update(t);
}
