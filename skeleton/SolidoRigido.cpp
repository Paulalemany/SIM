#include "SolidoRigido.h"

SolidoRigido::SolidoRigido(PxScene* _scene, PxPhysics* _physics, 
	PxTransform ori, Vector3 vel, Vector3 W, Vector3 tam, float d, Vector4 col)
{
	size = tam;
	solido = _physics->createRigidDynamic(ori);
	solido->setLinearVelocity(vel);
	solido->setAngularVelocity(W);

	PxShape* shape = CreateShape(PxBoxGeometry(tam));
	solido->attachShape(*shape);

	PxRigidBodyExt::updateMassAndInertia(*solido, d);	//El 0.15 es la densidad kg/m3
	_scene->addActor(*solido);

	item = new RenderItem(shape, solido, col);

}

void SolidoRigido::CreateStatic(PxScene* _scene, PxPhysics* _physics, PxTransform ori, Vector3 tam, Vector4 col)
{
	estatico = _physics->createRigidStatic(ori);
	PxShape* shapeEstatic = CreateShape(PxBoxGeometry(tam));
	estatico->attachShape(*shapeEstatic);
	_scene->addActor(*estatico);

	item= new RenderItem(shapeEstatic, estatico, col);

}

void SolidoRigido::addForce(Vector3 F)
{
	if (solido != nullptr) solido->addForce(F);
}
