#include "TorbellinoScene.h"

TorbellinoScene::TorbellinoScene()
{
	fuerzas.push_back(new TorbellinoGenerator(Vector3{ 10,35,0 }));
}

TorbellinoScene::~TorbellinoScene()
{

}

void TorbellinoScene::keyPressed(unsigned char key, const physx::PxTransform& camera)
{
	//Por ahora nada
}

bool TorbellinoScene::update(double t)
{
	//Ponemos particulas para ver el efecto
	if (particulas.size() == 0) {

		//Vamos a poner una por ahora
		Proyectil* p = new Proyectil({1, 20, 0}, {0,0,0}, {0,0,0}, 0.5);
		p->setLiveTime(500);
		p->setMasa(3);
		particulas.push_back(p);
	}

	return Scene::update(t);
}
