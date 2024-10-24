#pragma once
#include <vector>
#include <random>
#include "Proyectil.h"

//Clase padre de la que heredaran todos los generadores de particulas
class ParticleGenerator
{
public:
	ParticleGenerator(Vector3 o, Vector3 vel, int np);
	
	virtual std::vector<Proyectil*> CreateParticles(int actParticles, int maxParticles) = 0;

protected:
	Vector3 origen;	//Punto de origen
	Vector3 velMed;	//Velocidad media

	std::vector<Proyectil*> particulas;	//Coleccion de particulas
	std::default_random_engine generator;

	int numParticles;	//Numero de particulas
};

