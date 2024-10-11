#include "ParticleSystem.h"

ParticleSystem::ParticleSystem(Vector3 ori, Vector3 vel, int n)
{
	origen = ori;
	velMed = vel;
	numParticles = n;
}

void ParticleSystem::update(double t)
{
	//Actualiza el tiempo que lleva vivo
	//Actualizar su vector de particulas
		//Segun tiempo de vida
		//Segun posicion
	//Eliminar particulas que mueren
	//Hacer el update de las particulas

	//Generar particulas nuevas
		//Recorrer los generadores
		//Generar particulas
		//Añadir las particulas al vector
}
