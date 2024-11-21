#include "ParticleScene.h"

ParticleScene::ParticleScene()
{
	sistemas.push_back(new ParticleSystemFuegosArt(Vector3(0, 0, 0), Vector3(0, 20, 0), 10, 50000));	//Fuegos artificiales
}

ParticleScene::~ParticleScene()
{
}
