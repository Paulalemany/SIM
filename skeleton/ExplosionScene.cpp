#include "ExplosionScene.h"

ExplosionScene::ExplosionScene()
{
	fuerzas.push_back(new ExplosionGenerator({ 10,0,-60 }, 200));
}

ExplosionScene::~ExplosionScene()
{

}

bool ExplosionScene::update(double t)
{

	if (particulas.size() == 0) {

		for (int i = 0; i < 50; i++) {
			float x = 10, z = 10, y = 30;
			x *= cos(alpha * pi / 180);
			z *= sin(delta * pi / 180);

			alpha += anglesum;
			delta += anglesum;

			const Vector3 auxv = { x, y , z };

			Proyectil* p = new Proyectil(auxv, { 0,0,0 }, { 0,0,0 }, 0.5);
			p->setLiveTime(500);
			p->setMasa(0.1);

			particulas.push_back(p);
		}
		
	}
	return Scene::update(t);
}

void ExplosionScene::keyPressed(unsigned char key, const physx::PxTransform& camera)
{
	//Explota cuando se pulsa la tecla
}
