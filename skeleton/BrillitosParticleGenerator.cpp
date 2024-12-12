#include "BrillitosParticleGenerator.h"

BrillitosParticleGenerator::BrillitosParticleGenerator(Vector3 o, Vector3 vel, int np)
	:ParticleGenerator(o, vel, np)
{
}

std::vector<Proyectil*> BrillitosParticleGenerator::CreateParticles(int actParticles, int maxParticles)
{
	return std::vector<Proyectil*>();
}

std::vector<Particle*> BrillitosParticleGenerator::CreateStaticParticles(int actParticles, int maxParticles)
{
	std::vector <Particle*> aux;

	//Generamos un numero random de particulas
	int par = maxParticles - actParticles;	//Particulas maximas que podemos crear
	//if (actParticles >= maxParticles) par -= actParticles;

	std::uniform_int_distribution<int> distribution(0, par);
	std::uniform_int_distribution<int> distribution2(-100, 100);
	int numPar = distribution(generator);  // generates number in the range 1..par
	int liveTime;

	std::normal_distribution<double> Ndistribution(3, 3);

	double x, y, z;

	//creamos las particulas que toquen
	for (int i = 0; i < numPar; i++) {

		//Queremos randomizar la posicion
		x = distribution2(generator);
		y = distribution2(generator);
		z = distribution2(generator);
		liveTime = Ndistribution(generator);

		//Les pasamos la velocidad del viento
		aux.push_back(new Particle({ (float)x, (float)y, (float)z }, velMed, { 0.97, 0.97, 0.68, 1 }));
		aux[i]->setTam(0.5, 0);
		aux[i]->setLiveTime(liveTime);
	}

	return aux; return std::vector<Particle*>();
}
