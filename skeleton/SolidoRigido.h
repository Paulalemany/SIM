#pragma once
#include "Entidad.h"

using namespace physx;
class SolidoRigido : public Entidad
{
public:
	SolidoRigido() {}

	SolidoRigido(PxScene* _scene, PxPhysics* _physics, 
		PxTransform ori, Vector3 vel, Vector3 W, Vector3 tam, 
		float d, Vector4 col);

	~SolidoRigido() {

		if (item != nullptr) {
			DeregisterRenderItem(item);
		}
		if (solido != nullptr) solido->release();	//Release: Elimina el actor y todos sus componentes
		if (estatico != nullptr) estatico->release();
		
	}

	void CreateStatic(PxScene* _scene, PxPhysics* _physics,
		PxTransform ori, Vector3 tam, Vector4 col);

	///Setters
	void setInertia() {
		//Dentro simplemente se pone por el tama�o?
		solido->setMassSpaceInertiaTensor({ size.y * size.z, size.x * size.z, size.x * size.y});
	}
	void setPosition(Vector3 p) override
	{
		pose.p = p;
		solido->setGlobalPose(pose);
	}
	void setVelocidad(Vector3 v) override 
	{
		Lvel = v;
		solido->setLinearVelocity(Lvel);
	}

	void integrate(double t) override;

	///Fuerzas
	void addForce(Vector3 F) override;	//Los objetos dinamicos ya tienen un addForce

protected:
	RenderItem* item = nullptr;
	PxRigidDynamic* solido = nullptr;
	PxRigidStatic* estatico = nullptr;
	Vector3 size;

	Vector3 Lvel;
	Vector3 Wvel;

	//Le a�adimos tiempo de vida
	float liveTime = 500;

};

