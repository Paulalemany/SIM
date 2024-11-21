#include "Zone.h"

Zone::Zone(float r, physx::PxVec3 Pos)
{
	renderItem = new RenderItem(CreateShape(physx::PxSphereGeometry(radio)), 
		&physx::PxTransform(Pos), { 1, 0.0, 0.0, 0.01 });
}

Zone::~Zone()
{

}

void Zone::changeShape(physx::PxShape* shap)
{
	if (renderItem == nullptr)
		renderItem = new RenderItem(shap, &physx::PxTransform(position), { 1, 0.0, 0.0, 0.01 });
	else
		renderItem->shape = shap;
}
