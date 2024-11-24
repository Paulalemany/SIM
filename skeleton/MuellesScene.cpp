#include "MuellesScene.h"

MuellesScene::MuellesScene()
{
	generator = new MuelleParticleGenerator({ 0,0,0 }, { 0,0,0 }, 2);
	pium = generator->CreateParticles();
	
	//ancla = new Particle({0,0,0});
	//ancla->setLiveTime(500);
	//fuerzas.push_back(new MuelleForeGenerator({ 0,0,0 }, 5, 5.5, ancla));
	fuerzas.push_back(new MuelleForeGenerator({ 0,0,0 }, 5, 5.5, pium[0]));
}

MuellesScene::~MuellesScene()
{

}

void MuellesScene::update(double t)
{
	for (auto p : pium) p->update(t);

	//ancla->update(t);
}
