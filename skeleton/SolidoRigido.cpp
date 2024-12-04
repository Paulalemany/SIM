#include "SolidoRigido.h"

SolidoRigido::SolidoRigido(PxScene* _scene, PxPhysics* _physics, 
	PxTransform ori, Vector3 vel, Vector3 W, Vector3 tam, float d, Vector4 col)
{
	PxRigidDynamic* solido = _physics->createRigidDynamic(ori);
	solido->setLinearVelocity(vel);
	solido->setAngularVelocity(W);

	PxShape* shape = CreateShape(PxBoxGeometry(tam));
	solido->attachShape(*shape);

	PxRigidBodyExt::updateMassAndInertia(*solido, d);	//El 0.15 es la densidad kg/m3
	_scene->addActor(*solido);

	RenderItem* item = new RenderItem(shape, solido, col);

}

void SolidoRigido::CreateStatic(PxScene* _scene, PxPhysics* _physics, PxTransform ori, Vector3 tam, Vector4 col)
{
	PxRigidStatic* estatic = _physics->createRigidStatic(ori);
	PxShape* shapeEstatic = CreateShape(PxBoxGeometry(tam));
	estatic->attachShape(*shapeEstatic);
	_scene->addActor(*estatic);

	RenderItem* itemEstatic = new RenderItem(shapeEstatic, estatic, col);

}
