#include "FuegosArtificialesGenerator.h"

FuegosArtificialesGenerator::FuegosArtificialesGenerator(Vector3 o, Vector3 vel, int np)
	:ParticleGenerator(o, vel, np)
{
}

std::vector<Proyectil*> FuegosArtificialesGenerator::CreateParticles(int actParticles, int maxParticles)
{
	std::vector <Proyectil*> aux;

	//Cuantas mas particulas se generen mas continuo ira
	std::uniform_int_distribution<int> distribution(5, 15);
	int numPar = distribution(generator);  // generates number in the range 1..par

	//No se puede poner a 0 
	//Cuanto mas alto el n�mero menos seguidas y mas dispersas
	//La segunda cuanto mas alto menos dispersion
	std::fisher_f_distribution<double> Fdistribution(2.0, 2.0);
	std::fisher_f_distribution<double> FCdistribution(2.0, 2.0);


	//Expulsa la particulas como por impulsos
	//La primera variable cambia lo seguidas que van las particulas?
	//La segunda es la dispersion. Si se pone en los extremos 
	// hacen casi el mismo movimiento
	std::binomial_distribution<int> Bdistribution(5, 0.8);
	
	
	double r = FCdistribution(generator);
	double g = FCdistribution(generator);
	double b = FCdistribution(generator);

	Vector4 color(r, g, b, 1);

	
	Vector3 newVel;
	double x;
	int y;
	double z;

	for (int i = 0; i < numPar; i++) {

		x = Fdistribution(generator);
		y = Bdistribution(generator);
		z = Fdistribution(generator);

		Vector3 newVel(x, y, z);

		aux.push_back(new Proyectil(origen, newVel + velMed, Vector3(0, -10, 0), 1, color));
	}
	return aux;
}

std::vector<Proyectil*> FuegosArtificialesGenerator::CreateParticles(Vector4 color)
{

	std::vector <Proyectil*> aux;

	//Cuantas mas particulas se generen mas continuo ira
	std::uniform_int_distribution<int> distribution(5, 15);
	int numPar = distribution(generator);  // generates number in the range 1..par

	//No se puede poner a 0 
	//Cuanto mas alto el n�mero menos seguidas y mas dispersas
	//La segunda cuanto mas alto menos dispersion
	std::fisher_f_distribution<double> Fdistribution(2.0, 2.0);


	//Expulsa la particulas como por impulsos
	//La primera variable cambia lo seguidas que van las particulas?
	//La segunda es la dispersion. Si se pone en los extremos 
	// hacen casi el mismo movimiento
	std::binomial_distribution<int> Bdistribution(5, 0.8);

	Vector3 newVel;
	double x;
	int y;
	double z;

	for (int i = 0; i < numPar; i++) {

		x = Fdistribution(generator);
		y = Bdistribution(generator);
		z = Fdistribution(generator);

		Vector3 newVel(x, y, z);

		aux.push_back(new Proyectil(origen, newVel + velMed, Vector3(0, -10, 0), 1, color));
	}
	return aux;
}
