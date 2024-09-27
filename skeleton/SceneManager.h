#pragma once
#include <PxPhysicsAPI.h>

class SceneManager
{
public:
	void changeScene(int scene);
	enum escenas {
		PARTICULAS = 0
	};

private:
	//Creamos las escenas
	physx::PxScene* gScene = NULL;
};

