#pragma once
#include "SolidScene.h"
#include "ParticleSystemBrillitos.h"

extern std::string _start;
extern std::string _intro;
extern std::string _balas;
extern std::string _ExplicacionS;
extern std::string _ExplicacionM;
extern std::string _ExplicacionL;
extern std::string _fin;

class Start_Menu : public SolidScene
{
public:
	Start_Menu(PxScene* _scene, PxPhysics* _physics);


	///Para la gestion de escenas
	void init() override;	//Pone la escena
	void quit() override;	//Quita la escena

	void setWin(bool b) override { win = b; }
	bool getWin() { return win; }

private:
	bool win = false;
};

