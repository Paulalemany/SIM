#pragma once
#include "Particle.h"

class Proyectil : public Particle
{
public:
	//Constructora
	//Añadir un vector de gravedad
	Proyectil(Proyectil* p);	//Constructor por copia
	Proyectil(physx::PxVec3 Pos, physx::PxVec3 Vel, physx::PxVec3 a, double D);
	Proyectil(physx::PxVec3 Pos, physx::PxVec3 Vel, physx::PxVec3 a, double D, Vector4 color);
	~Proyectil() {};

	bool update(double t) override;

private:

	//Masa en gramos
	double masa = 1;

	//Gravedad en m/s
	Vector3 grav = Vector3 (0, -9.8, 0);
	
};

