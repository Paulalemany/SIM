#include "SolidoRigido.h"

SolidoRigido::SolidoRigido(PxScene* _scene, PxPhysics* _physics, 
	PxTransform ori, Vector3 vel, Vector3 W, Vector3 tam, float d, Vector4 col)
	: Entidad(ori.p, tam)
{
	size = tam;
	Lvel = vel;
	Wvel = W;

	solido = _physics->createRigidDynamic(ori);
	solido->setLinearVelocity(vel);
	solido->setAngularVelocity(W);

	shape = CreateShape(PxSphereGeometry(tam.x));
	solido->attachShape(*shape);

	PxRigidBodyExt::updateMassAndInertia(*solido, d);	//El 0.15 es la densidad kg/m3
	masa = solido->getMass();

	_scene->addActor(*solido);

	item = new RenderItem(shape, solido, col);

}

void SolidoRigido::CreateStatic(PxScene* _scene, PxPhysics* _physics, PxTransform ori, Vector3 tam, Vector4 col)
{
	pose = ori;
	color = col;
	size = tam;

	createCaja(ori.p,tam.x, tam.y, tam.z );
	estatico = _physics->createRigidStatic(ori);
	estatico->setGlobalPose(ori);
	
	shape= CreateShape(PxBoxGeometry(tam));
	estatico->attachShape(*shape);
	_scene->addActor(*estatico);

	item= new RenderItem(shape, estatico, col);

	///Shapes existentes
	//PxSphereGeometry
	//PxCapsuleGeometry
	//PxBoxGeometry

}

void SolidoRigido::changeShape(int s)
{
	item->release();

	switch (s)
	{
	case 0:
		shape = CreateShape(PxBoxGeometry(size));
		break;
	case 1:
		shape = CreateShape(PxCapsuleGeometry(size.x, size.y));
		break;
	case 2:
		shape = CreateShape(PxSphereGeometry(size.x));
		break;

	default:
		break;
	}

	item = new RenderItem(shape, estatico, color);
}

void SolidoRigido::integrate(double t)
{
	//Gestionamos con el tiempo de vida
	liveTime -= t;

	if (liveTime <= 0) alive = false;
}

void SolidoRigido::addForce(Vector3 F)
{
	if (solido != nullptr) solido->addForce(F);
}
