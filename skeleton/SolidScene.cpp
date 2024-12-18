#include "SolidScene.h"
#include <iostream>

SolidScene::SolidScene(PxScene* _scene, PxPhysics* _physics)
{
	scene = _scene;
	physics = _physics;

	mat = physics->createMaterial(1, 1, 0);
}

SolidScene::~SolidScene()
{
}

bool SolidScene::update(double t)
{
	///Particulas del gameplay
	if (bullet != nullptr) {
		bullet->update(t);

		//Aqui simplemente poner la condicion de victoria
		if (target->inBoundingBox(bullet->getPosition())) return true;
		for (auto f : fuerzas) {
			f->update(t);
			if (f->onZone(bullet->getPosition()))
				bullet->addForce(f->generateForce(*bullet));
		}

		//Fuerza a las particulas del sistema
		for (auto s : sistemas) s->update(t); 

		//Necesito comprobar las colisiones de la bala con el resto de objetos
		for (auto s : objetos)
			if (s->inBoundingBox(bullet->getPosition())) 
				bullet->setVelocidad({ 0,0,0 });
	}

	//la gestion de las fuerzas sobre la bala la hacemos aparte
	Scene::update(t);

	return false;
}

void SolidScene::keyPressed(unsigned char key, const physx::PxTransform& camera)
{
	switch (key)
	{
	case 's':
		std::cout << "---BALA PEQUE�A---\n";
		bulletColor = SbulletCol;
		bulletMasa = SbulletMasa;
		bulletTam = SbulletTam;

		break;
	case 'm':
		std::cout << "---BALA MEDIANA---\n";
		bulletColor = MbulletCol;
		bulletMasa = MbulletMasa;	//Con este se hunde pero mas o menos flota
		bulletTam = MbulletTam;
		break;
	case 'l':
		std::cout << "---BALA GRANDE---\n";
		bulletColor = LbulletCol;
		bulletMasa = LbulletMasa;	//Quiero que sea una masa que le haga undirse
		bulletTam = LbulletTam;
		break;
	default:
		break;
	}
}

void SolidScene::shoot(Vector3 pos)
{
	if (bullet != nullptr) bullet->~Particle();

	//La direccion es el vector que hay entre el punto pos y el origen
	PxVec3 dir = (pos - ori).getNormalized();
	bullet = new Proyectil(ori, dir * 40, { 0,0,0 }, 0.5, bulletColor);

	//Estas dos cosas y el color es lo que deberia variar con cada tipo de bala
	bullet->setMasa(bulletMasa);
	bullet->setTam({ bulletTam, bulletTam, bulletTam }, 0);
}

void SolidScene::init()
{

	SolidoRigido* O = new SolidoRigido();
	O->CreateStatic(scene, physics, { 0,0,0 }, { 0.5,0.5,0.5 }, { 1,1,1,1 });
	objetos.push_back(O);

	SolidoRigido* X = new SolidoRigido();
	X->CreateStatic(scene, physics, { 1,0,0 }, { 0.5,0.5,0.5 }, { 1,0,0,1 });
	objetos.push_back(X);

	SolidoRigido* Y = new SolidoRigido();
	Y->CreateStatic(scene, physics, { 0,1,0 }, { 0.5,0.5,0.5 }, { 0,1,0,1 });
	objetos.push_back(Y);


	//Voy a utilizarlo de ca�on
	SolidoRigido* P = new SolidoRigido();
	P->CreateStatic(scene, physics, { -20,0,0 }, { 0.5,0.5,0.5 }, { 0,0,0,1 });
	objetos.push_back(P);
}

void SolidScene::quit()
{
	//Esto seria por ahora eliminar todos los solidoRigidos del vector
	for (auto e : objetos) e->~SolidoRigido();
	if (canon != nullptr) canon->~Particle();
	if (bullet != nullptr) {
		bullet->~Particle();
		bullet = nullptr;
	}

	objetos.clear();

	Scene::quit();
	
}
