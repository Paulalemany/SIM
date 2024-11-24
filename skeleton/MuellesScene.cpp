#include "MuellesScene.h"

MuellesScene::MuellesScene()
{
	//Creamos dos particulas, el ancla y la que se mueve
	Proyectil* p = new Proyectil({ -10,20,0 }, { 0,0,0 }, { 0,0,0 }, 0.85);
	AnclaFG* ancla = new AnclaFG({ 10, 10, 0 }, 5, 10, { 10.0, 20, 0 });
	ancla->setRadio(100);

	p->setMasa(2);

	particulas.push_back(p);

	//Ponemos las fuerzas
	fuerzas.push_back(ancla);
}

MuellesScene::~MuellesScene()
{

}
