#include "ExplosionScene.h"

ExplosionScene::ExplosionScene()
{
	fuerzas.push_back(new ExplosionGenerator({ 10,35,0 }, 200));
	//fuerzas[0]->setRadio();
}

ExplosionScene::~ExplosionScene()
{

}

void ExplosionScene::update(double t)
{

	if (particulas.size() < 50) {
		float x = 10, z = 10, y = 30;
		x *= cos(alpha * pi / 180);
		z *= sin(delta * pi / 180);

		alpha += anglesum;
		beta += anglesum;
		delta += anglesum;

		const Vector3 auxv = { x, y , z};

		Proyectil* p = new Proyectil(auxv, { 0,0,0 }, { 0,0,0 }, 0.5);
		p->setLiveTime(500);
		p->setMasa(0.1);

		particulas.push_back(p);
	}
	Scene::update(t);
}
