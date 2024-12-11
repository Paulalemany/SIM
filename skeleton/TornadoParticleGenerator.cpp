#include "TornadoParticleGenerator.h"

TornadoParticleGenerator::TornadoParticleGenerator(Vector3 o, Vector3 vel, int np, float r)
	:ParticleGenerator(o, vel, np)
{
	radio = r;
}

std::vector<Proyectil*> TornadoParticleGenerator::CreateParticles(int actParticles, int maxParticles)
{
	return std::vector<Proyectil*>();
}

//Queremos que las particulas que muestran el torbellino 
std::vector<Particle*> TornadoParticleGenerator::CreateStaticParticles(int actParticles, int maxParticles)
{
	std::vector <Particle*> aux;

	//Generamos un numero random de particulas
	int par = maxParticles - actParticles;	//Particulas maximas que podemos crear

	std::uniform_int_distribution<int> distribution(0, par); // generates number in the range 1..par
	std::uniform_int_distribution<int> distribution2(0, 5);
	int numPar = distribution(generator);  
	int liveTime, masa;

	//La primera variable es la media, indica como de lejos van
	//La segunda en la desviacion tipica, indica la dispersion
	std::normal_distribution<double> Ndistribution(5000, 100.0);

	//creamos las particulas que toquen
	for (int i = 0; i < numPar; i++) {

		//Queremos randomizar la masa de las particulas y el tiempo
		
		liveTime = distribution2(generator);
		masa = Ndistribution(generator);

		//Les pasamos la velocidad del viento
		aux.push_back(new Particle({ origen.x, origen.y - radio, origen.z }, velMed, { 0.76, 0.76, 0.76, 0.5 }));
		aux[i]->setTam(0.3, 0);
		aux[i]->setMasa(masa);
		aux[i]->setLiveTime(liveTime);
	}

	return aux;
}
