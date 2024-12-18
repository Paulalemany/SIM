#pragma once
#include "SolidScene.h"
#include "ParticleSystemBrillitos.h"

extern std::string _fin;
extern std::string _nivelFlotacion;
extern std::string _nivelViento;
extern std::string _nivelTornado;
extern std::string _nivelSolidos;

class Text_Menu : public SolidScene
{
public:
	Text_Menu(PxScene* _scene, PxPhysics* _physics);

	///Para la gestion de escenas
	void init(int i);	//Pone la escena
	void quit() override;	//Quita la escena

private:
	enum texto {
		N_FLOTACION = 0,
		N_VIENTO,
		N_TORNADO,
		N_SOLIDOS,
		NIVELES,
		START
	};
};

