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
	//Target del nivel
	target->CreateStatic(scene, physics, { 20, -5, -0.5 }, { 2, 2, 2 }, { 0, 0, 0, 1 });

	//Para que no nos colisione con el cañon hago que este sea una particula 
	Particle* canon = new Particle({ -20, 0, 0 });
	canon->setTam(0.5, 1);

	//Muro que obliga a usar la flotacion
	SolidoRigido* muro = new SolidoRigido();
	muro->CreateStatic(scene, physics, { 0,10,0 }, { 1, 10, 1 }, { 1,1,1,1 });
	objetos.push_back(muro);

	//Le voy a hacer tambien un techo que me veo venir que lo hagan por arriba
	//Mejor trato de huir de las diagonales
	SolidoRigido* techo = new SolidoRigido();
	techo->CreateStatic(scene, physics, { -9, 20, 0 }, { 10, 1, 1 }, { 1,1,1,1 });
	objetos.push_back(techo);

	Scene::init();
}

void NivelFlotacion::quit()
{
	SolidScene::quit();
	Scene::quit();
}
