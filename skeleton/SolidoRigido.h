#pragma once
#include "RenderUtils.hpp"
#include <PxPhysicsAPI.h>

using namespace physx;
class SolidoRigido
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

	void setInertia() {
		//Dentro simplemente se pone por el tamaño?
		solido->setMassSpaceInertiaTensor({ size.y * size.z, size.x * size.z, size.x * size.y});
	}

	///Fuerzas
	void addForce(Vector3 F);	//Los objetos dinamicos ya tienen un addForce

protected:
	RenderItem* item = nullptr;
	PxRigidDynamic* solido = nullptr;
	PxRigidStatic* estatico = nullptr;
	Vector3 size;

	//Le añadimos tiempo de vida
	float liveTime = 500;

};

