#pragma once
#include <vector>
#include <random>
#include "Proyectil.h"

//Clase padre de la que heredaran todos los generadores de particulas
class ParticleGenerator
{
public:
	ParticleGenerator(Vector3 o, Vector3 vel, int np);

	ParticleGenerator(Vector3 o, Vector3 vel, int np, Vector4 col);
	
	virtual std::vector<Proyectil*> CreateParticles(int actParticles, int maxParticles) = 0;
	virtual std::vector<Particle*> CreateParticles();

	void setOrigin(Vector3 o) { origen = o; }
	Vector4 getColor() { return color; }

protected:
	Vector3 origen;	//Punto de origen
	Vector3 velMed;	//Velocidad media
	Vector4 color;	//Color de las particulas

	std::vector<Proyectil*> particulas;	//Coleccion de particulas
	std::default_random_engine generator;

	int numParticles;	//Numero de particulas
};

