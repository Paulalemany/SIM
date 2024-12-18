#pragma once
#include "Entidad.h"

using namespace physx;
class SolidoRigido : public Entidad
{
public:
	SolidoRigido() {}

	SolidoRigido(PxScene* _scene, PxPhysics* _physics, 
		PxTransform ori, Vector3 vel, Vector3 W, Vector3 tam, 
		int f, float bulletMass, Vector4 col);

	~SolidoRigido() {

		if (item != nullptr) {
			DeregisterRenderItem(item);
		}
		if (solido != nullptr) solido->release();	//Release: Elimina el actor y todos sus componentes
		if (estatico != nullptr) estatico->release();
		
	}

	void CreateStatic(PxScene* _scene, PxPhysics* _physics,
		PxTransform ori, Vector3 tam, Vector4 col);

	void changeShape(int s);

	///Setters
	void setInertia() {
		//Dentro simplemente se pone por el tamaño?
		solido->setMassSpaceInertiaTensor({ size.y * size.z, size.x * size.z, size.x * size.y});
	}
	void setPosition(Vector3 p) override
	{
		pose.p = p;
		if (solido != nullptr) solido->setGlobalPose(pose);
		else if (estatico != nullptr) estatico->setGlobalPose(pose);
	}
	void setVelocidad(Vector3 v) override 
	{
		Lvel = v;
		solido->setLinearVelocity(Lvel);
	}
	void setDensity(int f);

	Vector3 getPosition() override { return solido->getGlobalPose().p; }

	void integrate(double t) override;

	///Fuerzas
	void addForce(Vector3 F) override;	//Los objetos dinamicos ya tienen un addForce


	///Enum para los tipos de formas
	enum forma {
		CAJA = 0,
		CAPSULA,
		ESFERA
	};

protected:
	RenderItem* item = nullptr;
	PxShape* shape = nullptr;
	PxRigidDynamic* solido = nullptr;
	PxRigidStatic* estatico = nullptr;
	Vector3 size;
	Vector4 color;

	Vector3 Lvel;
	Vector3 Wvel;

	//Le añadimos tiempo de vida
	float liveTime = 500;

	float density = 0;

};

