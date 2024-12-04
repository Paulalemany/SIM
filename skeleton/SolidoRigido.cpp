#include "SolidoRigido.h"

SolidoRigido::SolidoRigido(PxScene* _scene, PxPhysics* _physics, PxTransform ori, Vector3 tam, Vector4 col)
{
	PxRigidDynamic* solido = _physics->createRigidDynamic(ori);

	PxShape* shape = CreateShape(PxBoxGeometry(tam));
	solido->attachShape(*shape);
	_scene->addActor(*solido);

	RenderItem* item = new RenderItem(shape, solido, col);

}
