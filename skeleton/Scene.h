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

	enum Generadores
	{
		Fuente = 0,
		FuegosArtificiales = 1,
		Humo = 2
	};

private:

	//Vector que gestiona las particulas de la escena
	vector<Particle*> particulas;
	ParticleSystem* fuente;
	ParticleSystem* fuegos;
	ParticleSystem* humo;
};

