#pragma once
#include "Particle.h"

class ForceGenerator
{
public:

	ForceGenerator(Vector3 ori);
	~ForceGenerator();

	//virtual Vector3 generateForce(Particle& par) = 0;
	bool onZone(Vector3 pos);

	virtual void update(double t);

	void setRadio(float r);

	virtual Vector3 generateForce(Particle& p);

	virtual void show();
	virtual void hide();

protected:

	//Propiedades de generadores de fuerzas
	float radio = 30; //Radio de la zona afectada
	Vector3 origen = { 0,0,0 };

	Particle* zona = nullptr;

	void generateZone();
};

