#include "GameMachine.h"

GameMachine::GameMachine()
{
	//Por ahora solo tenemos una escena estandar
	escenas.push_back(new ParticleScene());
	escenas.push_back(new ForcesScene());
	escenas.push_back(new VientoScene());
	escenas.push_back(new TorbellinoScene());
	escenas.push_back(new ExplosionScene());
	actual = VIENTO;	//Iniciamos automaticamente con la escena 0
}

GameMachine::~GameMachine()
{
}

void GameMachine::update(double t)
{
	//Solo hacemos el update de la escena en la que estamos
	escenas[actual]->update(t);
}

void GameMachine::changeScene(int s)
{
	if (s != actual) {

		//Ocultamos las particulas de la escena actual
		escenas[actual]->quit();
		//Ponemos en marcha los de la nueva
		escenas[s]->init();
		actual = s;
	}
	
}

void GameMachine::keyPressed(unsigned char key, const physx::PxTransform& camera)
{
	switch (key)
	{
	case '0':
		std::cout << "---ESCENA PARTICULAS---\n";
		changeScene(PARTICULAS);
		break;
	case '1':
		std::cout << "---ESCENA FUERZAS---\n";
		changeScene(FUERZAS);
		break;
	case '2':
		std::cout << "---ESCENA VIENTO---\n";
		changeScene(VIENTO);
		break;
	case '3':
		std::cout << "---ESCENA TORBELLINO---\n";
		changeScene(TORBELLINO);
		break;
	case '4':
		std::cout << "---ESCENA EXPLOSION---\n";
		changeScene(EXPLOSION);
		break;

	default:
		/*for (auto s : escenas)
			s->keyPressed(key, camera);*/
		break;
	}

}
