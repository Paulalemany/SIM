#include "ParticleSystemFuegosArt.h"
#include <iostream>

ParticleSystemFuegosArt::ParticleSystemFuegosArt(Vector3 ori, Vector3 vel, int n, int l)
	: ParticleSystem(ori, vel, n, l)
{
	fuegosGenerator = new FuegosArtificialesGenerator(origen, velMed, numParticles);
	generator = new OriginFuegoGenerator(origen, velMed, numParticles);
}

bool ParticleSystemFuegosArt::update(double t)
{
	//actualiza el tiempo que lleva vivo el sistema
	liveTime -= t;
	if (liveTime == 0) return false;

	//Primero generamos la particula de origen
	if (ini.size() == 0) {
		aux = generator->CreateParticles(ini.size(), 1);
	}

	//Anadimos las particulas de la explosion al vector
	for (int i = 0; i < aux.size(); i++) {	//Añadimos las particulas a nuestro vector

		Proyectil* p = new Proyectil(aux[i]);
		delete aux[i];
		p->setLiveTime(1);
		ini.push_back(p);
	}

	///Eliminamos aux
	aux.clear();

	//Actualizamos el tiempo de las particulas (Ambos)
	for (auto e : ini) e->restLiveTime(t);


	//Actualiza las particulas de la escena
	for (auto p : ini) {
		p->update(t);
	}
	
	//eliminacion de ini
	for (int i = 0; i < ini.size(); i++) {

		if (!ini[i]->getAlive()) {

			//Creamos aqui la explosion del fuego
			fuegosGenerator->setOrigin(ini[i]->getPosition());
			aux = fuegosGenerator->CreateParticles(generator->getColor());

			//Si esta muerta la eliminamos del vector
			delete ini[i];

			//Eliminamos tambien el puntero del vector
			auto ref = find(ini.begin(), ini.end(), ini[i]);
			ini.erase(ref);
			i--;
		}
	}
	
	
#pragma region Explosion

	//Anadimos las particulas de la explosion al vector
	for (int i = 0; i < aux.size(); i++) {	//Añadimos las particulas a nuestro vector

		Proyectil* p = new Proyectil(aux[i]);
		delete aux[i];
		p->setLiveTime(8);
		particulas.push_back(p);
	}

	///Eliminamos aux
	aux.clear();

	///Restamos tiempo de vida
	//Actualizar su vector de particulas
	for (auto e : particulas) e->restLiveTime(t);

	//Actualiza las particulas de la escena
	for (auto p : particulas) {
		p->update(t);
	}

	eliminaPart(particulas);
#pragma endregion

	return true;
}
