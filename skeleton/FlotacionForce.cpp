#include "FlotacionForce.h"
#include "iostream"

FlotacionForce::FlotacionForce(Vector3 ori, float _h, float _v, float _d)
	: ForceGenerator(ori)
{
	altura = _h;
	volumen = _v;
	densidad = _d;
	//Inicializamos la particula que representa al liquido aunque no tengo muy claro que es lo que hace
	particulaLiquida = new Particle(ori);	//Creo que es lo mismo que pongo ya para ver por donde actua el cuerpo
	particulaLiquida->setColor({ 0.33, 0.39, 0.92, 0.5 });
	particulaLiquida->setTam({ 50, 1, 50 }, 1);	//forma '1': cubo mide 10m de lado
}

Vector3 FlotacionForce::generateForce(Particle& p)
{
	Vector3 F = { 0,0,0 };

	float h = p.getPosition().y;					//Posicion punto medio del objeto
	float h0 = particulaLiquida->getPosition().y;	//Posicion superficie del agua

	float inmerso = 0;

	if (h - h0 > altura * 0.5) {
		inmerso = 0;
	}
	else if (h0 - h > altura * 0.5) {
		//Totalmente inmerso
		inmerso = 1;
	}
	else {
		inmerso = (h0 - h) / altura + 0.5;			//Profundidad normalizada
	}

	F.y = densidad * volumen * inmerso * gravedad;

	return F;
}

void FlotacionForce::show()
{
	particulaLiquida->setVisibility(true);
	ForceGenerator::show();
}

void FlotacionForce::hide()
{
	particulaLiquida->setVisibility(false);
	ForceGenerator::hide();
}
