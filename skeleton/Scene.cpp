
#include "Scene.h"

Scene::Scene()
{
	fuente = new ParticleSystemFuente(Vector3(0, 0, 0), Vector3(0, 25, -25), 500, 50000);

	//fuegos = new ParticleSystem(Vector3(0, 0, 0), Vector3(0, 40, 0), 10, 50000, FuegosArtificiales);

	humo = new ParticleSystemHumo(Vector3(0, 0, 0), Vector3(0, 20, 0), 10, 50000);

	//particulas.push_back(new Particle(Vector3(0, 0, 0), Vector3(0, 10, 0), Vector4(0, 1, 0, 1)));
}

Scene::~Scene()
{
	//Tareas
	//1.
	//Force Generator
	//Particle Force Registry (P, F)
	//Particle -> AddForce
	//		   -> ClearForce
	//2.
	//Gravity Force Generator
	//3.
	//Wind
	//Tornado
	//Blast

	//Integrate a = dccF/m
	//Particle -> iniMass
	//		   -> accF

	//Sumatorio F = m * a
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

	fuente->update(t);

	//fuegos->update(t);

	humo->update(t);
}

void Scene::addParticle(Particle* particula)
{
	//Anadimos la particula al vector de particulas
	particulas.push_back(particula);
}
