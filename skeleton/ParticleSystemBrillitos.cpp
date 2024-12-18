#include "ParticleSystemBrillitos.h"

ParticleSystemBrillitos::ParticleSystemBrillitos(Vector3 ori, Vector3 vel, int n, int l)
	:ParticleSystem(ori, vel, n, l)
{
	generator = new BrillitosParticleGenerator(ori, vel, n);
}

bool ParticleSystemBrillitos::update(double t)
{
	//Este sistema es inmortal

	//Creamos las particulas nuevas y las guardamos en el vector de particulas
	pAux = generator->CreateStaticParticles(particulas.size(), numParticles);

	for (int i = 0; i < pAux.size(); i++) {	//Añadimos las particulas a nuestro vector

		particulas.push_back(pAux[i]);
	}

	//Eliminar particulas que mueren
	//Actualiza las particulas de la escena
	for (auto p : particulas) {
		p->update(t);
			//Queremos ir cambiandole la opacidad poco a poco
		p->restTransparencia(0.01);
	}

	eliminaPart(particulas);


	return true;
}
