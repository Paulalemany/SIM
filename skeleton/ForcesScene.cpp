#include "ForcesScene.h"

ForcesScene::ForcesScene()
{
	fuerzas = new ForceGenerator(Vector3(0,0,0));
}

ForcesScene::~ForcesScene()
{
}
