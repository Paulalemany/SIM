#include "VientoScene.h"

VientoScene::VientoScene()
{
	//Añadimos las fuerzas
	fuerzas.push_back(new VientoGenerator(Vector3{-50,0,-20}, Vector3(50, 0, 0)));
	fuerzas[0]->setRadio(100);
}

VientoScene::~VientoScene()
{
}

void VientoScene::update(double t)
{
}
