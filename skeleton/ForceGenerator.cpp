#include "ForceGenerator.h"
#include <iostream>

ForceGenerator::ForceGenerator(Vector3 ori)
{
	origen = ori;
	// si ya existe un render item, elimina el que esta y crea uno nuevo con el nuevo radio
	if (!zona)
	{
		generateZone();
	}
}

ForceGenerator::~ForceGenerator()
{
}

bool ForceGenerator::onZone(Vector3 pos)
{
	//Comprueba si la posicion esta dentro del radio
	return (pos - origen).magnitude() <= radio;
}

void ForceGenerator::update(double t)
{
	
}

void ForceGenerator::setZone(float r)
{
	radio = r;
	generateZone();
}

void ForceGenerator::generateZone()
{
	//Creamos el renderItem
	//De forma estandar la geometria de la zona va a ser una esfera
	zona = new Particle(origen, radio, { 1,1,1,0.1 });
}
