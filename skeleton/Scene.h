#pragma once
#include <vector>
#include "ForceGenerator.h"
#include "ParticleSystem.h"

using namespace std;
class Scene
{
public:

	Scene();

	~Scene();

	virtual bool update(double t);

	void addParticle(Particle* particula);

	void eliminaPart();

	///Input de la escena
	virtual void keyPressed(unsigned char key, const physx::PxTransform& camera) = 0;

	/// Para la gestion de escenas
	virtual void init();	//Pone la escena
	virtual void quit();	//Quita la escena

protected:

	//Vector que gestiona las particulas de la escena
	vector<Particle*> particulas;
	vector<ParticleSystem*> sistemas;
	vector<ForceGenerator*> fuerzas;

	bool active = true;
};

