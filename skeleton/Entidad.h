#pragma once
#include "Interactivo.h"
#include "RenderUtils.hpp"

class Entidad : public Interactivo	//Todas las entidades son interactivas
{
public:
	Entidad() {}
	Entidad(Vector3 p, Vector3 s);

	virtual ~Entidad() {};

	///Getters
	int getVolumen() { return escala.x * escala.y * escala.z; }
	int getAltura() { return escala.y; }
	virtual Vector3 getPosition() { return pose.p; }
	bool isAlive() { return alive; }

	///Setters
	virtual void setPosition(Vector3 p) = 0;
	virtual void setVelocidad(Vector3 v) = 0;

	virtual void addForce(Vector3 F) = 0;	//Las particulas y solidos manejan las fuerzas de formas distintas
	virtual void integrate(double t) = 0;

	

protected:
	//Propiedades
	physx::PxTransform pose;	//Transform
	Vector3 escala;
	Vector3 vel;
	Vector4 color;
	float masa = 1;

	//Objetos
	RenderItem* item = nullptr;
	
	//Vida
	float liveTime = 500;	//Tiempo de vida estandar
	bool alive = true;		//De forma predeterminada estan vivas
};

