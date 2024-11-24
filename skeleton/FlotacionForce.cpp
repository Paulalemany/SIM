#include "FlotacionForce.h"

FlotacionForce::FlotacionForce(Vector3 ori, float _h, float _v, float _d)
	: ForceGenerator(ori)
{
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
