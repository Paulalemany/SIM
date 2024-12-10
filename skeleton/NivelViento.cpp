#include "NivelViento.h"
#include <iostream>

NivelViento::NivelViento(PxScene* _scene, PxPhysics* _physics)
	:SolidScene(_scene, _physics)
{

	//Añadimos la fuerza del viento
	fuerzas.push_back(new VientoGenerator({ 0,0,0 }, { -10, 10, 0 }));	//Ya veremos cuanta fuerza le ponemos al viento
	sistemas.push_back(new ParticleSystemViento({ 0,0,0 }, { -10, 10, 0 }, 100, 50000));
	viento = false;
}

void NivelViento::update(double t)
{
	//La base es igual que en la padre pero las fuerzas hay que cambiarlas
	if (bullet != nullptr) {
		bullet->update(t);

		//Comprobamos si ha llegado al target
		if (target->inBoundingBox(bullet->getPosition())) cout << " Buah como mola el viento";
		//Ponemos las fuerzas pero solo si esta activada
		if (viento) {
			fuerzas[0]->update(t);
			if (fuerzas[0]->onZone(bullet->getPosition())) bullet->addForce(fuerzas[0]->generateForce(*bullet));

			//Creamos particulas para simbolizar el viento? serviria un generador
			sistemas[0]->update(t);

		}

		//Comprobamos las colisiones con el resto de sitios
		for (auto o : objetos)
			if (o->inBoundingBox(bullet->getPosition()))
				bullet->setVelocidad({ 0,0,0 });	//Esto si me da tiempo cambiarlo porque seria increible ponerle efectos
	}
}

void NivelViento::keyPressed(unsigned char key, const physx::PxTransform& camera)
{
	SolidScene::keyPressed(key, camera);	//Lo que hacemos es ademas de lo que se hace en la clase padre

	//Con la v activamos y desactivamos el viento 
	if (key == 'v') {
		viento = !viento;

		if(viento) sistemas[0]->show();
		else sistemas[0]->hide();
	}

	cout << " viento: " << viento;
}

void NivelViento::init()
{
	Scene::init();

	///Creamos el nivel

	//Target del nivel
	target->CreateStatic(scene, physics, { -5, 5, -0.5 }, { 2, 2, 2 }, { 0, 0, 0, 1 });

	//Cañon
	Particle* canon = new Particle({ -20, 0, 0 });
	canon->setTam(0.5, 1);

	SolidoRigido* muro = new SolidoRigido();
	muro->CreateStatic(scene, physics, { -10, 0, 0 }, { 1, 10, 1 }, { 1,1,1,1 });
	objetos.push_back(muro);

	SolidoRigido* techo = new SolidoRigido();
	techo->CreateStatic(scene, physics, { -4, 10, 0 }, { 7, 1, 1 }, { 1,1,1,1 });
	objetos.push_back(techo);
}

void NivelViento::quit()
{
	viento = false;
	SolidScene::quit();
	Scene::quit();
}
