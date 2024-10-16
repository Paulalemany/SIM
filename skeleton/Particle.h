#pragma once
#include "RenderUtils.hpp"
#include <PxPhysicsAPI.h>

class Particle
{
public:

	Particle(physx::PxVec3 Pos, physx::PxVec3 Vel, Vector4 col);
	Particle(physx::PxVec3 Pos, Vector4 col, physx::PxVec3 a, double D);
	Particle(physx::PxVec3 Pos, physx::PxVec3 Vel, Vector4 col, physx::PxVec3 a, double D);
	~Particle();

	void integrate(double t);
	virtual bool update(double t);

	void restLiveTime();

protected:
	//Parametros de la particula
	physx::PxVec3 ace;
	physx::PxVec3 vel;	//Velocidad inicial
	Vector4 color;		//Color inicial 
	float tam;			//Tamaño inicial
	float trans;		//Transparencia inicial
	float timeLive;		//Tiempo de vida

	//0 < d < 1
	//Dumpling
	double d = 0.98;

	bool alive;
	int liveTime;

	//Al RenderItem le pasamos pose para que se actualice automaticamente
	physx::PxTransform pose;	//Posicion inicial
	RenderItem* renderItem;

	//Habría que poner la forma
};

