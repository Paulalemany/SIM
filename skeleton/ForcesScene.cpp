#include "ForcesScene.h"

ForcesScene::ForcesScene()
{
	fuerzas = new ForceGenerator(Vector3(-150,0,-100));
}

ForcesScene::~ForcesScene()
{
}

void ForcesScene::update(double t)
{
	fuerzas->update(t);
}
