#pragma once
#include "Scene.h"
#include "TorbellinoGenerator.h"

class TorbellinoScene : public Scene
{
public:
	TorbellinoScene();
	~TorbellinoScene();

	void update(double t) override;
};

