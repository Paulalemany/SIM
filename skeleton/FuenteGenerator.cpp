#include "FuenteGenerator.h"

FuenteGenerator::FuenteGenerator(Vector3 o, Vector3 vel, int np)
	:ParticleGenerator(o, vel, np)
{
	//Vamos a poner una particula estatica en el origen
	//Lo hace ya el particle generator
}

std::vector<Proyectil*> FuenteGenerator::CreateParticles(int actParticles, int maxParticles)
{
	std::vector <Proyectil*> aux;

	//Para numero de particulas
	int par = maxParticles - actParticles;

	//Cuantas mas particulas se generen mas continuo ira
	std::uniform_int_distribution<int> distribution(0, par);
	int numPar = distribution(generator);  // generates number in the range 1..6 


	//Para cambiar la velocidad (Solo quiero cambiar la x y la z
	//La primera variable es la media, indica como de lejos van
	//La segunda en la desviacion tipica, indica la dispersion
	std::normal_distribution<double> Ndistribution(5.0, 3.0);

	//Expulsa la particulas como por impulsos
	//La primera variable cambia lo seguidas que van las particulas?
	//La segunda es la dispersion. Si se pone en los extremos 
	// hacen casi el mismo movimiento
	std::binomial_distribution<int> Bdistribution(9, 0.5);

	//No se puede poner a 0 
	//Cuanto mas alto el número menos seguidas y mas dispersas
	//La segunda cuanto mas alto menos dispersion
	std::fisher_f_distribution<double> Fdistribution(2.0, 2.0);

	Vector3 newVel;
	double x;
	double y;
	double z;

	Vector4 color(0.33, 0.39, 0.92, 1);
	double r;
	double g;
	double b;

	for (int i = 0; i < numPar; i++) {

		x = Ndistribution(generator);
		y = Ndistribution(generator);
		z = Ndistribution(generator);

		////float x = Fdistribution(generator);
		//float y = Bdistribution(generator);
		//float z = Fdistribution(generator);

		/*r = Ndistribution(generator);
		g = Ndistribution(generator);
		b = Ndistribution(generator);*/

		newVel.x = x;
		newVel.y = y;
		newVel.z = z;

		/*color.x = r;
		color.y = g;
		color.z = b;*/

		aux.push_back(new Proyectil(origen, newVel + velMed, Vector3(0, -10, 0), 1, color));
		
	}

	return aux;
}
