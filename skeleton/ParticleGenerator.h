#pragma once
#include <vector>
#include "Proyectil.h"

//Clase padre de la que heredaran todos los generadores de particulas
class ParticleGenerator
{
public:
	ParticleGenerator(Vector3 o, Vector3 vel, int np);
	

protected:
	Vector3 origen;	//Punto de origen
	Vector3 velMed;	//Velocidad media

	std::vector<Proyectil*> particulas;	//Coleccion de particulas

	int numParticles;	//Numero de particulas
};

