
#include "Scene.h"

Scene::Scene()
{

	//sistemas.push_back(new ParticleSystemFuente(Vector3(0, 0, 0), Vector3(0, 25, -25), 500, 50000));	//Fuente
	//sistemas.push_back(new ParticleSystemFuegosArt(Vector3(0, 0, 0), Vector3(0, 20, 0), 10, 50000));	//Fuegos artificiales
	//sistemas.push_back(new ParticleSystemHumo(Vector3(0, 0, 0), Vector3(0, 20, 0), 10, 50000));			//Humo
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

	///Actualizamos los sistemas que haya
	if (active) {
		for (auto sys : sistemas) sys->update(t);
		for (auto p : particulas) p->update(t);

		eliminaPart();
	}
}

void Scene::addParticle(Particle* particula)
{
	//Anadimos la particula al vector de particulas
	particulas.push_back(particula);
}

void Scene::eliminaPart()
{
	for (int i = 0; i < particulas.size(); i++) {

		if (!particulas[i]->getAlive()) {

			//Si esta muerta la eliminamos del vector
			delete particulas[i];

			//Eliminamos tambien el puntero del vector
			auto ref = find(particulas.begin(), particulas.end(), particulas[i]);
			particulas.erase(ref);
			i--;
		}
	}
}

void Scene::init()
{
	//Volvemos a las particulas de la escena visibles
	//Las particulas estan dentro de los sistemas de particulas
	for (auto sys : sistemas) sys->show();
	for (auto p : particulas) p->setVisibility(true);

	active = true;
}

void Scene::quit()
{
	//Volvemos las particulas de la escena invisibles
	for (auto sys : sistemas) sys->hide();
	for (auto p : particulas) p->setVisibility(false);
	active = false;
}
