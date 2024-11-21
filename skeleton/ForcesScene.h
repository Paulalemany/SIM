#pragma once
#include "Scene.h"
#include "ForceGenerator.h"

class ForcesScene : public Scene
{
public:
	ForcesScene();
	~ForcesScene();

private:
	ForceGenerator* fuerzas = nullptr;
};

