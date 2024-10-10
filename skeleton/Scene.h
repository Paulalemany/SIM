
#pragma once

#include <vector>

//Las escenas por ahora solo tienen particulas
#include "Particle.h"

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
};

