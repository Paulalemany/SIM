#pragma once
#include "Scene.h"
#include "TorbellinoGenerator.h"

class TorbellinoScene : public Scene
{
public:
	TorbellinoScene();
	~TorbellinoScene();

	void keyPressed(unsigned char key, const physx::PxTransform& camera) override;

	bool update(double t) override;
};

