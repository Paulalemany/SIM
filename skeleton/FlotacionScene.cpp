#include "FlotacionScene.h"

FlotacionScene::FlotacionScene()
{
	//Ponemos la fuerza
	fuerzas.push_back(new FlotacionForce({ 0,30,0 }, 10, 1, 1000));

	//creamos la particula que flota
	Proyectil* p = new Proyectil({ 0,40,0 }, { 0,0,0 }, { 0,0,0 }, 0.85);
	p->setMasa(500);
	particulas.push_back(p);
}

FlotacionScene::~FlotacionScene()
{

}

void FlotacionScene::keyPressed(unsigned char key, const physx::PxTransform& camera)
{

}
