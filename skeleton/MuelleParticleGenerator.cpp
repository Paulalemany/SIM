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
	Particle* ancla = new Particle();
	Particle* p = new Particle({10,10,0}, {0.11,0.73,0.2, 1}, {0,0,0}, 0.85);
	p->setMasa(2);

	//Hay que ponerles tiempos de vida
	ancla->setLiveTime(500);
	p->setLiveTime(500);

	return aux;
}

std::vector<Particle*> MuelleParticleGenerator::CreateParticles()
{
	std::vector<Particle*> aux;

	//Creamos dos particulas, el ancla y la que se mueve
	Particle* ancla = new Particle();
	Particle* p = new Particle({ 10,10,0 }, { 0.11,0.73,0.2, 1 }, { 0,0,0 }, 0.85);
	p->setMasa(2);

	//Hay que ponerles tiempos de vida
	ancla->setLiveTime(500);
	p->setLiveTime(500);

	return aux;
}
