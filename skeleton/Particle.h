#pragma once
#include "Entidad.h"

class Particle : public Entidad
{
public:

	Particle(physx::PxVec3 Pos);
	Particle(physx::PxVec3 Pos, float r, Vector4 col);	//Particula estatica, solo para ver las zonas
	Particle(physx::PxVec3 Pos, physx::PxVec3 Vel, Vector4 col);
	Particle(physx::PxVec3 Pos, Vector4 col, physx::PxVec3 a, double D);
	Particle(physx::PxVec3 Pos, physx::PxVec3 Vel, Vector4 col, physx::PxVec3 a, double D);
	~Particle();

	void integrate(double t) override;
	virtual bool update(double t);
	void restLiveTime(double t);

	///Setters
	void setLiveTime(double t) { liveTime = t; }
	void setVisibility(bool vi);
	void setTam(float r, int shape);
	void setColor(Vector4 col) { color = col; }
	void setVelocidad(Vector3 v) override { vel = v; }
	void setPosition(Vector3 p) override { pose.p = p; pos = p; }

	Vector3 getVelocity() { return vel; }

	///Fuerzas
	virtual void addForce(Vector3 F) override {};
	virtual void applyForces() {};
	virtual void setMasa(float m) {};

protected:
	//Propiedades
	Vector3 pos;
	physx::PxVec3 ace;	//Aceleracion inicial
	float trans;		//Transparencia inicial

	//0 < d < 1
	//Dumpling
	double d = 0.98;

};

