#include "NivelFlotacion.h"
#include "iostream"

NivelFlotacion::NivelFlotacion(PxScene* _scene, PxPhysics* _physics)
	:SolidScene(_scene, _physics)
{
	//Añadimos la fuerza de flotacion a la escena
	//Los parametros son origen, altura del objeto que se sumerge, volumen y densidad
	fuerzas.push_back(new FlotacionForce({ 0,-10,0 }, 10, 10, 1000));

}

void NivelFlotacion::keyPressed(unsigned char key, const physx::PxTransform& camera)
{
	SolidScene::keyPressed(key, camera);

	switch (key)
	{
	case 's':
		fuerzas[0]->setAltura(1.0f);
		break;
	case 'm':
		fuerzas[0]->setAltura(2.0f);
		break;
	case 'l':
		fuerzas[0]->setAltura(4.0f);
		break;
	default:
		break;
	}
}

void NivelFlotacion::init()
{
	//Voy a utilizarlo de cañon
	SolidoRigido* P = new SolidoRigido();
	P->CreateStatic(scene, physics, { -20,0,0 }, { 0.5,0.5,0.5 }, { 0,0,0,1 });
	objetos.push_back(P);

	//Muro que obliga a usar la flotacion
	SolidoRigido* muro = new SolidoRigido();
	muro->CreateStatic(scene, physics, { 0,5,0 }, { 1, 10, 1 }, { 1,1,1,1 });
}

void NivelFlotacion::quit()
{
}
