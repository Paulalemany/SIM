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
	//Actualiza el tiempo que lleva vivo
	liveTime--;
	if (liveTime == 0) return false;
	

	//Actualizar su vector de particulas
	for (auto e : particulas) e->restLiveTime();

	//Eliminar particulas que mueren
	//Actualiza las particulas de la escena
	for (auto p : particulas) {

		//Solo queremos que actualice a las que estan vivas
		if (!p->update(t)) {

			//Si esta muerta la eliminamos del vector
			delete p;

			//Eliminamos tambien el puntero del vector
			auto ref = find(particulas.begin(), particulas.end(), p);
			particulas.erase(ref);
		}
	}

	//Generar particulas nuevas
		//Recorrer los generadores
		//Generar particulas
		//Añadir las particulas al vector

	return true;
}
