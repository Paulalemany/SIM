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

private:

	//Vector que gestiona las particulas de la escena
	vector<Particle*> particulas;
	ParticleSystem* fuente;
	ParticleSystem* fuegos;
	ParticleSystem* humo;
};

