#pragma once
#include <vector>
#include "Proyectil.h"

//Clase padre de la que heredaran todos los generadores de particulas
class ParticleGenerator
{
public:

protected:

	//Punto de origen
	std::vector<Proyectil*> particulas;
	int numParticles;
};

