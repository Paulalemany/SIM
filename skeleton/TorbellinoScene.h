#pragma once
#include "Scene.h"

class TorbellinoScene : public Scene
{
public:
	TorbellinoScene();
	~TorbellinoScene();

	void update(double t) override;
};

