#pragma once
#include <vector>
#include "Particle.h"
#include "ParticleSystem.h"

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
	ParticleSystem* sistema;
};

