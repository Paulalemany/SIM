#include "NivelSolidos.h"

NivelSolidos::NivelSolidos(PxScene* _scene, PxPhysics* _physics)
	:SolidScene(_scene, _physics)
{
}

bool NivelSolidos::update(double t)
{
	return false;
}

void NivelSolidos::keyPressed(unsigned char key, const physx::PxTransform& camera)
{
}

void NivelSolidos::shoot(Vector3 pos)
{
	if (solidBullet != nullptr) solidBullet->~SolidoRigido();	//Solo queremos una bala en escena

	//La direccion es el vector que hay entre el punto pos y el origen
	Vector3 dir = (pos - ori).getNormalized();

	//Esta vez la bala es un solido dinamico
	solidBullet = new SolidoRigido(scene, physics,
		{ oriSolid.x, oriSolid.y, oriSolid.z }, dir * 25, { 0,0,0 }, { bulletTam, bulletTam, bulletTam }, 
		0.5f, bulletColor);
}

void NivelSolidos::init()
{

	//Ponemos el cañon
	canon = new Particle(oriSolid);
	canon->setTam(0.5, 1);

	//Vamos a poner un suelo a ver que pasa
	SolidoRigido* suelo = new SolidoRigido();
	suelo->CreateStatic(scene, physics, { 0,-10,0 }, { 10, 1, 1 }, { 1,1,1,1 });

	//Vamos a probar los distintos tensores de inercia
}

void NivelSolidos::quit()
{
}
