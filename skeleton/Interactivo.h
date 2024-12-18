#pragma once
#include "core.hpp"
#include <PxPhysicsAPI.h>

//Clase padre para los objetos que sean interativos (Botones etc)
using _tipo = std::string;	//Para mejor lectura

class Interactivo
{
public:
	_tipo tipo;
	Interactivo() {};	//Constructora vacia
	Interactivo(Vector3 _pos, float h, float w, float l);

	//Comprobacion de colisiones
	bool inBoundingBox(Vector3 _pos);
	void createCaja(Vector3 _pos, float h, float w, float l);

protected:

	Vector3 pos;

	float altura;
	float ancho;
	float largo;

	struct BoundingBox {	//Pongo las 3 coordenadas aunque mi idea es que sea un mundo "2D"
		float minX, maxX;
		float minY, maxY;
		float minZ, maxZ;
	};

	BoundingBox Caja;

};

