#pragma once
#include "Proyectil.h"

class ParticleSystem
{
public:

	ParticleSystem(Vector3 ori, Vector3 vel, int n, int l);

	bool update(double t);

private:

	//Generador de particulas
	std::vector<Proyectil*> particulas;
	Vector3 origen;
	Vector3 velMed;
	int numParticles;

	int liveTime;

	//Forma de dispersion
	//Circular...
	//Conos...

};

