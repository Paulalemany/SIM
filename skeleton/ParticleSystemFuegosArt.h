#pragma once
#include "ParticleSystem.h"
#include "FuegosArtificialesGenerator.h"
#include "OriginFuegoGenerator.h"

class ParticleSystemFuegosArt : public ParticleSystem
{
public:

	ParticleSystemFuegosArt(Vector3 ori, Vector3 vel, int n, int l);
	bool update(double t) override;

	void show() override;
	void hide() override;

private:

	std::vector<Proyectil*> ini;	//Particula que inicia el fuego
	Vector4 color;
	FuegosArtificialesGenerator* fuegosGenerator;	//Generador para el origen del fuego
};

