#include "NivelTornado.h"

NivelTornado::NivelTornado(PxScene* _scene, PxPhysics* _physics)
	:SolidScene(_scene, _physics)
{
	//Añadimos las fuerzas
	fuerzas.push_back(new TorbellinoGenerator({ 0,0,0 }));

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
}

void NivelTornado::quit()
{
	SolidScene::quit();
}
