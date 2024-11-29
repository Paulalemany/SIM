#include "FlotacionScene.h"

FlotacionScene::FlotacionScene()
{
	//Ponemos la fuerza
	fuerzas.push_back(new FlotacionForce({ 0,30,0 }, 10, 10, 1000));

	//creamos la particula que flota
	Proyectil* p = new Proyectil({ 10,60,0 }, { 0,0,0 }, { 0,0,0 }, 0.85);
	Proyectil* p2 = new Proyectil({ -10,60,0 }, { 0,0,0 }, { 0,0,0 }, 0.85);
	p->setMasa(500);
	p2->setMasa(5000);
	particulas.push_back(p);
	particulas.push_back(p2);
}

FlotacionScene::~FlotacionScene()
{

}

void FlotacionScene::keyPressed(unsigned char key, const physx::PxTransform& camera)
{

}
