#include "NivelTornado.h"

NivelTornado::NivelTornado(PxScene* _scene, PxPhysics* _physics)
	:SolidScene(_scene, _physics)
{
	//Añadimos las fuerzas
	fuerzas.push_back(new TorbellinoGenerator({ 0,0,0 }));
	fuerzas[0]->setRadio(5);

	//Cuando esté hecho habrá que ponerle el sistema de particulas
}

void NivelTornado::update(double t)
{

	//ya veremos como hay que hacerlo aqui para que funcione
	SolidScene::update(t);
}

void NivelTornado::keyPressed(unsigned char key, const physx::PxTransform& camera)
{
	//Ya veremos como lo hacemos aqui también
	SolidScene::keyPressed(key, camera);
}

void NivelTornado::init()
{

	///Creamos el nivel

	target = new SolidoRigido();
	target->CreateStatic(scene, physics, { 20, 0, 0 }, { 2,2,2 }, { 0,0,0,1 });
	objetos.push_back(target);

	canon = new Particle({ -20, 0, 0 });
	canon->setTam(0.5, 1);
}

void NivelTornado::quit()
{
	SolidScene::quit();
}
