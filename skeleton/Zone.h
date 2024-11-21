#pragma once
#include "RenderUtils.hpp"
#include <PxPhysicsAPI.h>

class Zone
{
public:
	Zone(float r, physx::PxVec3 Pos);
	~Zone();

	void changeShape(physx::PxShape* shap);

protected:

	Vector3 position = { 0,0,0 };
	float radio = 5;
	RenderItem* renderItem;
};

