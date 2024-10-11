#pragma once
#include "Proyectil.h"

class ParticleSystem
{
public:

	ParticleSystem(Vector3 ori, Vector3 vel, int n);

	void update(double t);

private:

	//Generador de particulas
	std::vector<Proyectil*> particulas;
	Vector3 origen;
	Vector3 velMed;
	int numParticles;

	//Forma de dispersion
	//Circular...
	//Conos...

};

