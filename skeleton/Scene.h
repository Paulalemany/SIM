#pragma once
#include <vector>
#include "Particle.h"
#include "ParticleSystemFuente.h"
#include "ParticleSystemHumo.h"
#include "ParticleSystemFuegosArt.h"

using namespace std;
class Scene
{
public:

	Scene();

	~Scene();

	void update(double t);

	void addParticle(Particle* particula);

		/// Para la gestion de escenas
	void init();	//Pone la escena
	void quit();	//Quita la escena

protected:

	//Vector que gestiona las particulas de la escena
	vector<Particle*> particulas;
	vector<ParticleSystem*> sistemas;

	bool active = true;
};

