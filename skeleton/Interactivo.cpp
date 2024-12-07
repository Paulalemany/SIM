#include "Interactivo.h"

Interactivo::Interactivo(Vector3 _pos, float h, float w, float l)
{
	pos = _pos;
	altura = h;
	ancho = w;
	largo = l;

	//Creamos la boundingBox
	Caja.minX = pos.x - ancho;
	Caja.maxX = pos.x + ancho;

	Caja.minY = pos.y - altura;
	Caja.maxY = pos.y + altura;
	
	Caja.minZ = pos.z - largo;
	Caja.maxZ = pos.z + largo;
}

void Interactivo::createCaja(Vector3 _pos, float h, float w, float l)
{
	pos = _pos;
	altura = h;
	ancho = w;
	largo = l;

	//Creamos la boundingBox
	Caja.minX = pos.x - ancho;
	Caja.maxX = pos.x + ancho;

	Caja.minY = pos.y - altura;
	Caja.maxY = pos.y + altura;

	Caja.minZ = pos.z - largo;
	Caja.maxZ = pos.z + largo;
}

bool Interactivo::inBoundingBox(Vector3 _pos)
{
	//Si la posicion esta dentro de la caja es true
	//Es decir la posicion debe estar dentro de todos los parametros
	return _pos.x > Caja.minX && _pos.x < Caja.maxX &&
		_pos.y > Caja.minY && _pos.y < Caja.maxY &&
		_pos.z > Caja.minZ && _pos.z < Caja.maxZ;
}
