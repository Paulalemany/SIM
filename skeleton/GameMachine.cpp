#include "GameMachine.h"

GameMachine::GameMachine(PxScene* s, PxPhysics* p)
{
	//Por ahora solo tenemos una escena estandar
	escenas.push_back(new ParticleScene());
	escenas.push_back(new ForcesScene());
	escenas.push_back(new VientoScene());
	escenas.push_back(new TorbellinoScene());
	escenas.push_back(new ExplosionScene());
	escenas.push_back(new MuellesScene());
	escenas.push_back(new AnclaScene());
	escenas.push_back(new FlotacionScene());
	escenas.push_back(new SolidScene(s, p));
	actual = SOLIDOS;	//Escena con la que iniciamos

	//Escondemos todas las que no sean la escena actual
	for (int i = 0; i < escenas.size(); i++) {
		if (i != actual) escenas[i]->quit();
	}
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
	case '5':
		std::cout << "---ESCENA MUELLES---\n";
		changeScene(MUELLES);
		break;
	case '6':
		std::cout << "---ESCENA ANCLA---\n";
		changeScene(ANCLA);
		break;
	case '7':
		std::cout << "---ESCENA FLOTACION---\n";
		changeScene(FLOTACION);
		break;
	case '8':
		std::cout << "---ESCENA SOLIDOS---\n";
		changeScene(SOLIDOS);
		break;

	default:

		escenas[actual]->keyPressed(key, camera);
		break;
	}

}
