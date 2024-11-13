#include "ParticleSystemFuegosArt.h"
#include <iostream>

ParticleSystemFuegosArt::ParticleSystemFuegosArt(Vector3 ori, Vector3 vel, int n, int l)
	: ParticleSystem(ori, vel, n, l)
{
	generator = new FuegosArtificialesGenerator(origen, velMed, numParticles);
}

bool ParticleSystemFuegosArt::update(double t)
{
	//actualiza el tiempo que lleva vivo el sistema
	liveTime -= t;
	if (liveTime == 0) return false;

	//Primero generamos la particula de origen
	if (ini.size() == 0) {
		ini.push_back(new Proyectil(Vector3(0, 0, 0), Vector3(0, 100, 0), Vector3(0.5, 2, 0), 0.5));
		ini[0]->setLiveTime(2);
	}

	//Actualizamos el vector de particulas (Ambos)
	for (auto e : ini) e->restLiveTime(t);


	//Eliminar particulas que mueren
	//Actualiza las particulas de la escena
	for (auto p : ini) {
		p->update(t);
	}
	

	for (int i = 0; i < ini.size(); i++) {

		if (!ini[i]->getAlive()) {

			//Creamos aqui la explosion del fuego
			//aux = generator->CreateParticles(particulas.size(), numParticles);
			aux.push_back(new Proyectil(Vector3(0, 0, 0), Vector3(0, -1, 0), Vector3(0, 0, 0), 0, Vector4(1, 1, 1, 1)));

			//Si esta muerta la eliminamos del vector
			delete ini[i];

			//Eliminamos tambien el puntero del vector
			auto ref = find(ini.begin(), ini.end(), ini[i]);
			ini.erase(ref);
			i--;
		}
	}
	
	

	for (int i = 0; i < aux.size(); i++) {	//Añadimos las particulas a nuestro vector

		aux[i]->setLiveTime(2);
		particulas.push_back(aux[i]);
		
	}

	//Actualizar su vector de particulas
	//for (auto e : particulas) e->restLiveTime(t);

	//Eliminar particulas que mueren
	//Actualiza las particulas de la escena
	for (auto p : particulas) {
		p->update(t);
	}

	for (int i = 0; i < particulas.size(); i++) {

		if (!particulas[i]->getAlive()) {

			//Si esta muerta la eliminamos del vector
			delete particulas[i];

			//Eliminamos tambien el puntero del vector
			auto ref = find(particulas.begin(), particulas.end(), particulas[i]);
			particulas.erase(ref);
			i--;

			std::cout << "eliminamos";
		}
	}

	return true;
}
