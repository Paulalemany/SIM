#include "SolidScene.h"
#include <iostream>

SolidScene::SolidScene(PxScene* _scene, PxPhysics* _physics)
{
	scene = _scene;
	physics = _physics;

	mat = physics->createMaterial(1, 1, 0);

	//Vamos a hacer esto un poco de mala manera para testear
	target = new SolidoRigido();
	target->CreateStatic(scene, physics, { 20, 0, -0.5 }, { 2, 2, 2 }, { 0, 0, 0, 1 });	//Todas las escenas tendran un target
}

SolidScene::~SolidScene()
{
}

void SolidScene::update(double t)
{
	///Particulas del gameplay
	if (bullet != nullptr) {
		bullet->update(t);

		if (target->inBoundingBox(bullet->getPosition()));	//Aqui simplemente poner la condicion de victoria
		for (auto f : fuerzas) {
			f->update(t);
			if (f->onZone(bullet->getPosition())) bullet->addForce(f->generateForce(*bullet));
		}
	}

	//la gestion de las fuerzas sobre la bala la hacemos aparte
	Scene::update(t);
}

void SolidScene::keyPressed(unsigned char key, const physx::PxTransform& camera)
{
	switch (key)
	{
	case 's':
		std::cout << "---BALA PEQUEÑA---\n";
		bulletColor = { 0, 0, 1, 1 };
		bulletMasa = 10;
		bulletTam = 0.5;

		break;
	case 'm':
		std::cout << "---BALA MEDIANA---\n";
		bulletColor = { 1, 0, 0, 1 };
		bulletMasa = 1000;
		bulletTam = 1;
		break;
	case 'l':
		std::cout << "---BALA GRANDE---\n";
		bulletColor = { 0, 1, 0, 1 };
		bulletMasa = 5000;
		bulletTam = 2;
		break;
	default:
		break;
	}
}

void SolidScene::shoot(Vector3 pos)
{
	if (bullet != nullptr) bullet->~Particle();

	//La direccion es el vector que hay entre el punto pos y el origen
	PxVec3 ori = { -20, 0, 0 };
	PxVec3 dir = (pos - ori).getNormalized();
	bullet = new Proyectil(ori, dir * 40, { 0,0,0 }, 0.5, bulletColor);

	//Estas dos cosas y el color es lo que deberia variar con cada tipo de bala
	bullet->setMasa(bulletMasa);
	bullet->setTam(bulletTam, 0);
}

void SolidScene::init()
{
	///Vamos a dibujar los ejes
	SolidoRigido* O = new SolidoRigido();
	O->CreateStatic(scene, physics, { 0,0,0 }, { 0.5,0.5,0.5 }, { 1,1,1,1 });
	objetos.push_back(O);

	SolidoRigido* X = new SolidoRigido();
	X->CreateStatic(scene, physics, { 1,0,0 }, { 0.5,0.5,0.5 }, { 1,0,0,1 });
	objetos.push_back(X);

	SolidoRigido* Y = new SolidoRigido();
	Y->CreateStatic(scene, physics, { 0,1,0 }, { 0.5,0.5,0.5 }, { 0,1,0,1 });
	objetos.push_back(Y);


	//Voy a utilizarlo de cañon
	SolidoRigido* P = new SolidoRigido();
	P->CreateStatic(scene, physics, { -20,0,0 }, { 0.5,0.5,0.5 }, { 0,0,0,1 });
	objetos.push_back(P);
}

void SolidScene::quit()
{
	//Esto seria por ahora eliminar todos los solidoRigidos del vector
	for (auto e : objetos) e->~SolidoRigido();
	
}
