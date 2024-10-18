#include "FuenteGenerator.h"
#include <iostream>

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
	std::uniform_int_distribution<int> distribution(0, par);
	int numPar = distribution(generator);  // generates number in the range 1..6 


	//Para cambiar la velocidad (Solo quiero cambiar la x y la z
	//La primera variable es la media, indica como de lejos van
	//La segunda en la desviacion tipica, indica la dispersion
	std::normal_distribution<double> Ndistribution(5.0, 10.0);


	std::binomial_distribution<int> Bdistribution(9, 0.5);

	Vector3 newVel;

	for (int i = 0; i < numPar; i++) {

		double x = Ndistribution(generator);
		double y = Ndistribution(generator);
		double z = Ndistribution(generator);

		/*int x = Bdistribution(generator);
		int y = Bdistribution(generator);
		int z = Bdistribution(generator);*/

		newVel.x = x;
		newVel.y = y;
		newVel.z = z;

		aux.push_back(new Proyectil(origen, newVel, Vector3(0, -10, 0), 1));
		
	}

	return aux;
}
