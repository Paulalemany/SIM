#include "ForceGenerator.h"
#include <iostream>

ForceGenerator::ForceGenerator(Vector3 ori)
{
	radio = 5;
	origen = { 0,0,0 };
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

void ForceGenerator::setZone(float r)
{
	radio = r;
	generateZone();
}

void ForceGenerator::generateZone()
{
	//Creamos el renderItem
	//De forma estandar la geometria de la zona va a ser una esfera
	/*zone = new RenderItem(CreateShape(physx::PxSphereGeometry(radio)), &physx::PxTransform(origen), { 1, 1.0, 1.0, 1 });
	RegisterRenderItem(zone);*/

	Vector4 color = { 1,1,1,1 };
	physx::PxTransform pos = physx::PxTransform(origen);

	renderItem = new RenderItem(
		CreateShape(physx::PxSphereGeometry(5)),
		&pos,
		color
	);

	//RegisterRenderItem(zone);
}
