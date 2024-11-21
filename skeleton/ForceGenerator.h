#pragma once
#include "RenderUtils.hpp"
#include "Particle.h"
#include "Zone.h"

class ForceGenerator
{
public:

	ForceGenerator(Vector3 ori);
	~ForceGenerator();

	//virtual Vector3 generateForce(Particle& par) = 0;
	bool onZone(Vector3 pos);

	void update(double t);

	void setZone(float r);

private:

	//Propiedades de generadores de fuerzas
	float radio = 5; //Radio de la zona afectada
	Vector3 origen = { 0,0,0 };


	RenderItem* renderItem = nullptr;
	Zone* zona = nullptr;

	void generateZone();
};

