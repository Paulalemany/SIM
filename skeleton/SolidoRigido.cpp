#include "SolidoRigido.h"

SolidoRigido::SolidoRigido(PxScene* _scene, PxPhysics* _physics, 
	PxTransform ori, Vector3 vel, Vector3 W, Vector3 tam, int f, Vector4 col)
	: Entidad(ori.p, tam)
{
	size = tam;
	Lvel = vel;
	Wvel = W;

	solido = _physics->createRigidDynamic(ori);
	solido->setLinearVelocity(vel);
	solido->setAngularVelocity(W);

	//Hacemos la forma que queramos
	if(f == CAJA) shape = CreateShape(PxBoxGeometry(tam));
	else if (f == CAPSULA) shape = CreateShape(PxCapsuleGeometry(tam.x, tam.y));
	else if (f == ESFERA) shape = CreateShape(PxSphereGeometry(tam.x));
	
	solido->attachShape(*shape);
	masa = solido->getMass();

	setDensity(f);
	PxRigidBodyExt::updateMassAndInertia(*solido, density);
	

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
	case CAJA:
		shape = CreateShape(PxBoxGeometry(size));
		break;
	case CAPSULA:
		shape = CreateShape(PxCapsuleGeometry(size.x, size.y));
		break;
	case ESFERA:
		shape = CreateShape(PxSphereGeometry(size.x));
		break;

	default:
		break;
	}

	item = new RenderItem(shape, estatico, color);
}

void SolidoRigido::setDensity(int f)
{
	//Calculamos el volumen de la esfera cuando cambiamos la esfera
	float V = 0;

	if (f == CAJA) V = size.x * size.y * size.z;
	else if (f == CAPSULA) V = 0;	//pi * h * r * r
	else if (f == ESFERA) V = (4 / 3) * PxPi * size.x * size.x * size.x;

	density = masa / V;
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
