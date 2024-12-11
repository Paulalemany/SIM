#pragma once
#include "ParticleSystem.h"
#include "TornadoParticleGenerator.h"
#include "TorbellinoGenerator.h"

class ParticleSystemTornado : public ParticleSystem
{
public:

	ParticleSystemTornado(Vector3 ori, Vector3 vel, int n, int l, float r);

	bool update(double t) override;

private:
	std::vector<Particle*> staticAux;

	//para que se muevan las particulas siguiendo el tornado voy a poner aqui otra fuerza identica a la de la escena
	TorbellinoGenerator* fuerza = nullptr;
};

