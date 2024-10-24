
#include "Scene.h"

Scene::Scene()
{
	//fuente = new ParticleSystem(Vector3(0, 0, 0), Vector3(0, 25, -25), 500, 50000, Fuente);

	//fuegos = new ParticleSystem(Vector3(0, 0, 0), Vector3(0, 40, 0), 10, 50000, FuegosArtificiales);

	humo = new ParticleSystem(Vector3(0, 0, 0), Vector3(0, 20, 0), 10, 50000, Humo);
}

Scene::~Scene()
{

}

void Scene::update(double t)
{
	//Actualiza las particulas de la escena
	//for (Particle* p : particulas) {

	//	//Solo queremos que actualice a las que estan vivas
	//	if (!p->update(t)) {

	//		//Si esta muerta la eliminamos del vector
	//		delete p;

	//		//Eliminamos tambien el puntero del vector
	//		auto ref = find(particulas.begin(), particulas.end(), p);
	//		particulas.erase(ref);
	//	}
	//}

	//fuente->update(t);

	//fuegos->update(t);

	humo->update(t);
}

void Scene::addParticle(Particle* particula)
{
	//Anadimos la particula al vector de particulas
	particulas.push_back(particula);
}
