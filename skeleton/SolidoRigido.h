#pragma once
#include "RenderUtils.hpp"
#include <PxPhysicsAPI.h>

using namespace physx;
class SolidoRigido
{
public:
	SolidoRigido(PxScene* _scene, PxPhysics* _physics, 
		PxTransform ori, Vector3 vel, Vector3 W, Vector3 tam, 
		float d, Vector4 col);

protected:

};

