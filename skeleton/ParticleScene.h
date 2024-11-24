#pragma once
#include "Scene.h"
#include "ParticleSystemFuegosArt.h"

class ParticleScene : public Scene
{
public:
	ParticleScene();
	~ParticleScene();

	void keyPressed(unsigned char key, const physx::PxTransform& camera) override;

private:

};

