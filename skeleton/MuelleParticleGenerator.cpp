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

std::vector<Particle*> MuelleParticleGenerator::CreateParticles()
{
	std::vector<Particle*> aux;

	//Creamos dos particulas, el ancla y la que se mueve
	Proyectil* p = new Proyectil({ -10,20,0 }, { 0,0,0 }, { 0,0,0 }, 0.85);
	AnclaFG* ancla = new AnclaFG({ 10, 10, 0 }, 1, 10, { 10.0, 20, 0 });

	p->setMasa(2);

	aux.push_back(p);

	return aux;
}
