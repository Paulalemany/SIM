#include "ParticleSystem.h"

ParticleSystem::ParticleSystem(Vector3 ori, Vector3 vel, int n, int l)
{
	origen = ori;
	velMed = vel;
	numParticles = n;
	liveTime = l;
}

bool ParticleSystem::update(double t)
{

	//Actualiza el tiempo que lleva vivo el sistema
	liveTime -= t;
	if (liveTime == 0) return false;


	//Creamos las particulas nuevas y las guardamos en el vector de particulas
	//Deberia hacer aqui el random? Para que no se creen en cada frame
	aux = generator->CreateParticles(particulas.size(), numParticles);

	for (int i = 0; i < aux.size(); i++) {	//Añadimos las particulas a nuestro vector

		particulas.push_back(aux[i]);
	}

	//Actualizar su vector de particulas
	for (auto e : particulas) e->restLiveTime(t);

	//Eliminar particulas que mueren
	//Actualiza las particulas de la escena
	for (auto p : particulas) {
		p->update(t);
	}

	eliminaPart(particulas);
	

	return true;
}

void ParticleSystem::eliminaPart(std::vector<Proyectil*> par)
{
	for (int i = 0; i < particulas.size(); i++) {

		if (!particulas[i]->getAlive()) {

			//Si esta muerta la eliminamos del vector
			delete particulas[i];

			//Eliminamos tambien el puntero del vector
			auto ref = find(particulas.begin(), particulas.end(), particulas[i]);
			particulas.erase(ref);
			i--;
		}
	}
}
