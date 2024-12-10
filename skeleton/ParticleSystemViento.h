#pragma once
#include "ParticleSystem.h"
#include "VientoParticleGenerator.h"

class ParticleSystemViento : public ParticleSystem
{
public:

	ParticleSystemViento(Vector3 ori, Vector3 vel, int n, int l);

	bool update(double t) override;

	//tal vez tengo que poner un metodo para pararlas y ocultarlas aqui

private:
	std::vector<Particle*> staticAux;
};

