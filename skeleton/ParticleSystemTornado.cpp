#include "ParticleSystemTornado.h"

ParticleSystemTornado::ParticleSystemTornado(Vector3 ori, Vector3 vel, int n, int l, float r)
	:ParticleSystem(ori, vel, n, l)
{
	generator = new TornadoParticleGenerator(ori, vel, n, r);
	fuerza = new TorbellinoGenerator(ori);
	fuerza->setRadio(r);
}

bool ParticleSystemTornado::update(double t)
{
	//Actualiza el tiempo que lleva vivo el sistema
	liveTime -= t;
	if (liveTime == 0) return false;


	//Creamos las particulas nuevas y las guardamos en el vector de particulas
	//Deberia hacer aqui el random? Para que no se creen en cada frame
	aux = generator->CreateParticles(particulas.size(), numParticles);

	for (int i = 0; i < staticAux.size(); i++) {	//Añadimos las particulas a nuestro vector

		particulas.push_back(staticAux[i]);
	}

	//Eliminar particulas que mueren
	//Actualiza las particulas de la escena

	//Añadimos la fuerza al propio sistema de particulas para que le sigan?
	for (auto p : particulas) {
		p->update(t);

		if (fuerza->onZone(p->getPosition()))
			p->addForce(fuerza->generateForce(*p));
	}

	eliminaPart(particulas);


	return true;
}
