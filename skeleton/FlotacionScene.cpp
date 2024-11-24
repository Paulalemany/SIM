#include "FlotacionScene.h"

FlotacionScene::FlotacionScene()
{
	//Ponemos la fuerza
	fuerzas.push_back(new FlotacionForce({ 0,30,0 }, 5, 10, 1));

	//creamos la particula que flota
	Proyectil* p = new Proyectil({ 0,40,0 }, { 0,0,0 }, { 0,0,0 }, 0.85);
	p->setMasa(10);
	particulas.push_back(p);
}

FlotacionScene::~FlotacionScene()
{

}

void FlotacionScene::keyPressed(unsigned char key, const physx::PxTransform& camera)
{

}
