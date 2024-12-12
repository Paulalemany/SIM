#pragma once
#include <iostream>

//Escenas de las practicas
#include "ParticleScene.h"
#include "ForcesScene.h"
#include "ExplosionScene.h"
#include "TorbellinoScene.h"
#include "VientoScene.h"
#include "AnclaScene.h"
#include "FlotacionScene.h"
#include "SolidScene.h"

//Niveles
#include "NivelFlotacion.h"
#include "NivelViento.h"
#include "NivelTornado.h"

//Referencias para los textos
extern std::string _name;
extern std::string _start;
extern std::string _intro;
extern std::string _selector;
extern std::string _nivelFlotacion;
extern std::string _nivelViento;
extern std::string _nivelTornado;
extern std::string _fin;


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
		ANCLA,
		FLOTACION,
		SOLIDOS,
	};

	const enum Niveles {
		N_FLOTACION = 0,
		N_VIENTO,
		N_TORNADO
	};

	//Escenas
	vector<Scene*> escenas;
	vector<SolidScene*> niveles;
};

