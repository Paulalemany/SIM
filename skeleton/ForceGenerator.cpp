#include "ForceGenerator.h"
#include <iostream>

ForceGenerator::ForceGenerator(Vector3 ori)
{
	origen = ori;
	generateZone();
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

void ForceGenerator::setRadio(float r)
{
	radio = r;
	show();
	generateZone();
}

Vector3 ForceGenerator::generateForce(Particle& p)
{
	//Vamos a tomar esto como si fuese inverso a la gravedad
	Vector3 F = { 0,0,0 };
	F = { 0, 2 * 9.8, 0 };	//Es la inversa de la gravedad simplemente
	return F;
}

void ForceGenerator::show()
{
	//zona->setVisibility(true);
}

void ForceGenerator::hide()
{
	//zona->setVisibility(false);
}

void ForceGenerator::generateZone()
{
	//if (zona != nullptr) {
	//	zona->~Particle();
	//}

	////Creamos el renderItem
	////De forma estandar la geometria de la zona va a ser una esfera
	//zona = new Particle(origen, radio, { 1,1,1, 0.5 });

	//hide();
}
