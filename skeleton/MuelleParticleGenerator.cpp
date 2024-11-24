#include "MuelleParticleGenerator.h"

MuelleParticleGenerator::MuelleParticleGenerator(Vector3 o, Vector3 vel, int np)
	: ParticleGenerator(o, vel, np)
{
}

MuelleParticleGenerator::~MuelleParticleGenerator()
{
}

std::vector<Proyectil*> MuelleParticleGenerator::CreateParticles(int actParticles, int maxParticles)
{
	std::vector<Proyectil*> aux;

		//Creamos dos particulas, el ancla y la que se mueve
	Particle* p = new Particle({10,10,0}, {0.11,0.73,0.2, 1}, {0,0,0}, 0.85);
	p->setMasa(2);

	//Hay que ponerles tiempos de vida
	p->setLiveTime(500);


	return aux;
}

std::vector<Proyectil*> MuelleParticleGenerator::CreateParticles()
{
	std::vector<Proyectil*> aux;

	//Creamos dos particulas, el ancla y la que se mueve
	Particle* ancla = new Particle({-10, 10, 0});
	Proyectil* p = new Proyectil({ 10,10,0 }, { 0,0,0 }, { 0,0,0 }, 0.85);

	p->setMasa(2);

	//Hay que ponerles tiempos de vida
	ancla->setLiveTime(500);
	p->setLiveTime(500);

	aux.push_back(p);

	return aux;
}
