#pragma once
#include "Scene.h"
#include "ForceGenerator.h"

class ForcesScene : public Scene
{
public:
	ForcesScene();
	~ForcesScene();

	void keyPressed(unsigned char key, const physx::PxTransform& camera) override;

};

