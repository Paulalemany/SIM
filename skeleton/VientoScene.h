#pragma once
#include "Scene.h"
#include "VientoGenerator.h"

class VientoScene : public Scene
{
public:
	VientoScene();
	~VientoScene();

	void update(double t)override;

};

