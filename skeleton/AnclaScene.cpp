#include "AnclaScene.h"

AnclaScene::AnclaScene()
{	
	//Creamos dos particulas, el ancla y la que se mueve
	fuerzas.push_back(new VientoGenerator({ 0,0,0 }, { 10, 10, 0 }));

	Proyectil* p = new Proyectil({ -10,20,0 }, { 0,0,0 }, { 0,0,0 }, 0.85);
	ancla = new AnclaFG({ 10, 10, 0 }, 5, 10, { 10.0, 20, 0 });
	ancla->setRadio(100);

	//Proyectil* p2 = new Proyectil({ -20,0,0 }, { 0,0,0 }, { 0,0,0 }, 0.85);

	p->setMasa(2);
	//p2->setMasa(2);

	particulas.push_back(p);
	//particulas.push_back(p2);

	//Ponemos las fuerzas
	fuerzas.push_back(ancla);
}

AnclaScene::~AnclaScene()
{
}

void AnclaScene::keyPressed(unsigned char key, const physx::PxTransform& camera)
{
	//Queremos que se ejecute una fuerza
	//Podemos poner un viento que se ejecute tocando la v

	switch (key)
	{
	case 'v':
		//No se si esto funciona en mi cabeza esto lo invierte
		viento = !viento;
		break;
	default:
		break;
	}
}

void AnclaScene::update(double t)
{
	///Actualizamos los sistemas que haya
	if (active) {
		for (auto sys : sistemas) sys->update(t);

		for (auto p : particulas) {

			//La primera de fuerzas solo lo hacemos si esta activo
			if (viento) {
				fuerzas[0]->update(t);
				if (fuerzas[0]->onZone(p->getPosition())) p->addForce(fuerzas[0]->generateForce(*p));
			}

			//Hacemos la fuerza del muelle
			fuerzas[1]->update(t);
			if (fuerzas[1]->onZone(p->getPosition())) p->addForce(fuerzas[1]->generateForce(*p));
			
			p->update(t);
		}

		eliminaPart();
	}
}

void AnclaScene::init()
{
	//ancla->show();
	Scene::init();
}

void AnclaScene::quit()
{
	//ancla->hide();
	Scene::quit();
}
