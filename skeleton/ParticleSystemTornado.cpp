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
	//Este sistema es inmortal


	//Creamos las particulas nuevas y las guardamos en el vector de particulas
	//Deberia hacer aqui el random? Para que no se creen en cada frame
	aux = generator->CreateParticles(particulas.size(), numParticles);

	for (int i = 0; i < aux.size(); i++) {	//Añadimos las particulas a nuestro vector

		particulas.push_back(aux[i]);
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

void ParticleSystemTornado::show()
{
	fuerza->show();
	ParticleSystem::show();
}

void ParticleSystemTornado::hide()
{
	fuerza->hide();
	ParticleSystem::hide();
}
