#pragma once
#include <iostream>

#include "ParticleScene.h"
#include "ForcesScene.h"
#include "ExplosionScene.h"
#include "TorbellinoScene.h"
#include "VientoScene.h"
#include "MuellesScene.h"
#include "AnclaScene.h"
#include "FlotacionScene.h"
#include "SolidScene.h"


class GameMachine
{
public:
	GameMachine(PxScene* s, PxPhysics* p);
	~GameMachine();

	void update(double t);

	void changeScene(int s);

	void keyPressed(unsigned char key, const physx::PxTransform& camera);

	void shoot(PxVec3 pos);

private:
	int actual = 0;

	//Escenas
	//IMPORTANTE: el orden en el que metemos las escenas en el vector debe ser igual al valor del enum
	const enum Scenes {
		PARTICULAS = 0,
		FUERZAS,
		VIENTO,
		TORBELLINO,
		EXPLOSION,
		MUELLES,
		ANCLA,
		FLOTACION,
		SOLIDOS
	};

	//Escenas
	std::vector<Scene*> escenas;

	Particle* bullet = nullptr;
};

