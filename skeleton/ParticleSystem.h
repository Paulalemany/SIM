#pragma once
#include "Proyectil.h"
#include "FuenteGenerator.h"
#include "FuegosArtificialesGenerator.h"

class ParticleSystem
{
public:

	ParticleSystem(Vector3 ori, Vector3 vel, int n, int l, int ge);

	bool update(double t);

private:

	//Generador de particulas
	std::vector<Proyectil*> particulas;
	std::vector<Proyectil*> aux;
	Vector3 origen;
	Vector3 velMed;
	int numParticles;

	//Generador asociado
	ParticleGenerator* generator;

	int liveTime;

	//Forma de dispersion
	//Circular...
	//Conos...

};

