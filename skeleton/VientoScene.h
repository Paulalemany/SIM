#pragma once
#include "Scene.h"
#include "VientoGenerator.h"

class VientoScene : public Scene
{
public:
	VientoScene();
	~VientoScene();

	bool update(double t)override;
	void keyPressed(unsigned char key, const physx::PxTransform& camera) override;

};

