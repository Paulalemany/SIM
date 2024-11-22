#pragma once
#include "RenderUtils.hpp"
#include <PxPhysicsAPI.h>

class Particle
{
public:

	Particle();
	Particle(physx::PxVec3 Pos, float r, Vector4 col);	//Particula estatica, solo para ver las zonas
	Particle(physx::PxVec3 Pos, physx::PxVec3 Vel, Vector4 col);
	Particle(physx::PxVec3 Pos, Vector4 col, physx::PxVec3 a, double D);
	Particle(physx::PxVec3 Pos, physx::PxVec3 Vel, Vector4 col, physx::PxVec3 a, double D);
	~Particle();

	void integrate(double t);

	virtual bool update(double t);

	void restLiveTime(double t);

	///Setters

	void setLiveTime(double t) { liveTime = t; }
	void setVisibility(bool vi);

	///Getters
	bool getAlive() { return alive; }

	Vector3 getPosition() { return pos; }
	Vector3 getVelocity() { return vel; }

	///Fuerzas
	virtual void addForce(Vector3 F) {};
	virtual void applyForces() {};
	virtual void setMasa(float m) {};

protected:
	//Parametros de la particula
	Vector3 pos;
	physx::PxVec3 ace;	//Aceleracion inicial
	physx::PxVec3 vel;	//Velocidad inicial
	Vector4 color;		//Color inicial 

	float tam;			//Tamaño inicial
	float trans;		//Transparencia inicial
	float timeLive;		//Tiempo de vida

	//0 < d < 1
	//Dumpling
	double d = 0.98;

	bool alive;
	double liveTime;

	//Al RenderItem le pasamos pose para que se actualice automaticamente
	physx::PxTransform pose;	//Posicion inicial
	RenderItem* renderItem;

};

