#include "ForcesScene.h"

ForcesScene::ForcesScene()
{
	sistemas.push_back(new ParticleSystemFuente(Vector3(0, 0, 0), Vector3(0, 25, -25), 500, 50000));
}

ForcesScene::~ForcesScene()
{
}
