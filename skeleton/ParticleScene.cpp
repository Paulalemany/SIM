#include "ParticleScene.h"

ParticleScene::ParticleScene()
{
	sistemas.push_back(new ParticleSystemFuegosArt(Vector3(0, 0, 0), Vector3(0, 20, 0), 10, 50000));	//Fuegos artificiales
}

ParticleScene::~ParticleScene()
{
}

void ParticleScene::keyPressed(unsigned char key, const physx::PxTransform& camera)
{
	//Por ahora no queremos hacer nada
}
