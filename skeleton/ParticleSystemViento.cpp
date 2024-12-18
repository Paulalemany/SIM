#include "ParticleSystemViento.h"

ParticleSystemViento::ParticleSystemViento(Vector3 ori, Vector3 vel, int n, int l)
	:ParticleSystem(ori, vel, n, l)
{
	generator = new VientoParticleGenerator(origen, velMed, numParticles);
}

bool ParticleSystemViento::update(double t)
{
	//Quiero que este sistema no muera por tiempo


	//Creamos las particulas nuevas y las guardamos en el vector de particulas
	//Deberia hacer aqui el random? Para que no se creen en cada frame
	staticAux = generator->CreateStaticParticles(particulas.size(), numParticles);

	for (int i = 0; i < staticAux.size(); i++) {	//A�adimos las particulas a nuestro vector

		particulas.push_back(staticAux[i]);
	}

	//Eliminar particulas que mueren
	//Actualiza las particulas de la escena
	for (auto p : particulas) {
		p->update(t);
	}

	eliminaPart(particulas);


	return true;
}
