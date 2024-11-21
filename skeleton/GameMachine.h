#pragma once
#include <iostream>

#include "Scene.h"
#include "ParticleScene.h"
#include "ForcesScene.h"


class GameMachine
{
public:
	GameMachine();
	~GameMachine();

	void update(double t);

	void changeScene(int s);

	void keyPressed(unsigned char key, const physx::PxTransform& camera);;

private:
	int actual = 0;

	//Escenas
	//IMPORTANTE: el orden en el que metemos las escenas en el vector debe ser igual al valor del enum
	const enum Scenes {
		Particulas = 0,
		Fuerzas = 1
	};

	//Escenas
	std::vector<Scene*> escenas;
	Scene* particulas = nullptr;
};

