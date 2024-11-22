#include "MuellesScene.h"

MuellesScene::MuellesScene()
{
	generator = new MuelleParticleGenerator({ 0,0,0 }, { 0,0,0 }, 2);
	particulas = generator->CreateParticles(0, 0);
	 
	//fuerzas.push_back(new MuelleForeGenerator({ 0,0,0 }, 5, 5.5, p));
}

MuellesScene::~MuellesScene()
{

}

void MuellesScene::update(double t)
{

}
