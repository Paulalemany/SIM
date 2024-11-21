
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
	for (auto sys : sistemas) sys->update(t);
	
}

void Scene::addParticle(Particle* particula)
{
	//Anadimos la particula al vector de particulas
	particulas.push_back(particula);
}

void Scene::init()
{
	//Volvemos a las particulas de la escena visibles
	//Las particulas estan dentro de los sistemas de particulas
	for (auto sys : sistemas) sys->show();

	active = true;
}

void Scene::quit()
{
	//Volvemos las particulas de la escena invisibles
	for (auto sys : sistemas) sys->hide();
	active = false;
}
