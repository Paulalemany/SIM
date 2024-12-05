#pragma once
#include "Particle.h"
#include <vector>

class Proyectil : public Particle
{
public:
	//Constructora
	Proyectil();
	Proyectil(Proyectil* p);	//Constructor por copia
	Proyectil(physx::PxVec3 Pos, physx::PxVec3 Vel, physx::PxVec3 a, double D);
	Proyectil(physx::PxVec3 Pos, physx::PxVec3 Vel, physx::PxVec3 a, double D, Vector4 color);
	~Proyectil() {};

	bool update(double t) override;

	///Fuerzas
	void addForce(Vector3 F) override { fuerzas.push_back(F); }
	void applyForces() override;

	///Setters
	void setMasa(float m) override { masa = m; }

private:

	//Fuerzas
	std::vector<Vector3> fuerzas;	//Fuerzas que actuan sobre la particula

	//Gravedad en m/s
	Vector3 grav = Vector3 (0, -9.8, 0);
	
};

