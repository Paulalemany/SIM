#pragma once
#include <vector>
#include "ParticleSystemFuente.h"
#include "ParticleSystemHumo.h"
#include "ParticleSystemFuegosArt.h"

using namespace std;
class Scene
{
public:

	Scene();

	~Scene();

	virtual void update(double t);

	void addParticle(Particle* particula);

	void eliminaPart();

		/// Para la gestion de escenas
	virtual void init();	//Pone la escena
	virtual void quit();	//Quita la escena

protected:

	//Vector que gestiona las particulas de la escena
	vector<Particle*> particulas;
	vector<ParticleSystem*> sistemas;

	bool active = true;
};

