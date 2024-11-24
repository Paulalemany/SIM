#pragma once
#include "Scene.h"
#include "FlotacionForce.h"

class FlotacionScene : public Scene
{
public:
	FlotacionScene();
	~FlotacionScene();

	void keyPressed(unsigned char key, const physx::PxTransform& camera) override;

};

