#pragma once
#include "ParticleSystem.h"
#include "FuegosArtificialesGenerator.h"

class ParticleSystemFuegosArt : public ParticleSystem
{
public:

	ParticleSystemFuegosArt(Vector3 ori, Vector3 vel, int n, int l);
	bool update(double t) override;

private:

	std::vector<Proyectil*> ini;	//Particula que inicia el fuego

};

