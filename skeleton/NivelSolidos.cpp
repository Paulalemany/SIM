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
	Vector3 ori = { -20, 0, 0 };
	Vector3 dir = (pos - ori).getNormalized();

	//Esta vez la bala es un solido dinamico
	solidBullet = new SolidoRigido(scene, physics,
		{ ori.x, ori.y, ori.z }, dir * 40, { 0,0,0 }, { bulletTam, bulletTam, bulletTam }, 
		0.5f, bulletColor);
}

void NivelSolidos::init()
{
}

void NivelSolidos::quit()
{
}
