#include "VientoParticleGenerator.h"

VientoParticleGenerator::VientoParticleGenerator(Vector3 o, Vector3 vel, int np)
	:ParticleGenerator(o, vel, np)
{
}

std::vector<Proyectil*> VientoParticleGenerator::CreateParticles(int actParticles, int maxParticles)
{
	std::vector <Proyectil*> aux;

	//Generamos un numero random de particulas
	int par = maxParticles - actParticles;	//Particulas maximas que podemos crear
	//if (actParticles >= maxParticles) par -= actParticles;

	std::uniform_int_distribution<int> distribution(0, par);
	int numPar = distribution(generator);  // generates number in the range 1..par

	//La primera variable es la media, indica como de lejos van
	//La segunda en la desviacion tipica, indica la dispersion
	std::normal_distribution<double> Ndistribution(20, 10.0);
	double x, y, z;

	//creamos las particulas que toquen
	for (int i = 0; i < numPar; i++) {

		//Queremos randomizar la posicion
		//Tambien necesitaria que apareciesen por debajo pero bueno
		x = origen.x - Ndistribution(generator);
		y = origen.y - Ndistribution(generator);
		z = origen.z - Ndistribution(generator);
		
		//Les pasamos la velocidad del viento
		aux.push_back(new Proyectil({(float)x, (float)y, (float)z}, velMed, {0,0,0}, 0.8, {0.69, 1, 1, 1}));
		aux[i]->setTam({ 0.3, 0.3, 0.3 }, 0);
	}

	return aux;
}

std::vector<Particle*> VientoParticleGenerator::CreateStaticParticles(int actParticles, int maxParticles)
{
	std::vector <Particle*> aux;

	//Generamos un numero random de particulas
	int par = maxParticles - actParticles;	//Particulas maximas que podemos crear
	//if (actParticles >= maxParticles) par -= actParticles;

	std::uniform_int_distribution<int> distribution(0, par);
	std::uniform_int_distribution<int> distribution2(0, 5);
	std::uniform_int_distribution<int> distribution3(-1, 1);
	int numPar = distribution(generator);  // generates number in the range 1..par
	int liveTime;

	//La primera variable es la media, indica como de lejos van
	//La segunda en la desviacion tipica, indica la dispersion
	std::normal_distribution<double> Ndistribution(20, 10.0);
	double x, y, z;
	double nx, ny, nz;

	//creamos las particulas que toquen
	for (int i = 0; i < numPar; i++) {

		nx = distribution3(generator);
		if (nx == 0) nx = -1;
		ny = distribution3(generator);
		if (ny == 0) ny = -1;
		nz = distribution3(generator);
		if (nz == 0) nz = -1;
 

		//Quiero que haya una probabilidad 50% de que sea en el sitio negativo
		//Queremos randomizar la posicion
		x = (origen.x + Ndistribution(generator)) * nx;
		y = (origen.y + Ndistribution(generator)) * ny;
		z = (origen.z + Ndistribution(generator)) * nz;

		liveTime = distribution2(generator);

		//Les pasamos la velocidad del viento
		aux.push_back(new Particle({ (float)x, (float)y, (float)z }, velMed, { 0.69, 1, 1, 1 }));
		aux[i]->setTam({ 0.3, 0.3, 0.3 }, 0);
		aux[i]->setLiveTime(liveTime);
	}

	return aux;
}
