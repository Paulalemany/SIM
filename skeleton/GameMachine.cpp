#include "GameMachine.h"
#include <iostream>

GameMachine::GameMachine(PxScene* s, PxPhysics* p)
{
	//Por ahora solo tenemos una escena estandar
	escenas.push_back(new ParticleScene());
	escenas.push_back(new ForcesScene());
	escenas.push_back(new VientoScene());
	escenas.push_back(new TorbellinoScene());
	escenas.push_back(new ExplosionScene());
	escenas.push_back(new AnclaScene());
	escenas.push_back(new FlotacionScene());
	escenas.push_back(new SolidScene(s, p));

	niveles.push_back(new NivelFlotacion(s, p));
	niveles.push_back(new NivelViento(s, p));
	niveles.push_back(new NivelTornado(s, p));
	niveles.push_back(new NivelSolidos(s, p));
	niveles.push_back(new Niveles_Menu(s, p));
	niveles.push_back(new Start_Menu(s, p));
	actual = N_SOLIDOS;	//Escena con la que iniciamos

	for (int i = 0; i < niv; i++) botones.push_back(rest);
	niveles[NIVELES]->setColors(botones);

	//Escondemos todas las que no sean la escena actual
	for (int i = 0; i < escenas.size(); i++) escenas[i]->quit(); //Ahora que estamos con el proyecto final voy a ignorar las escenas
	for (int i = 0; i < niveles.size(); i++) niveles[i]->quit(); //Tambien escondemos todos los niveles

	niveles[actual]->init();
}

GameMachine::~GameMachine()
{
}

void GameMachine::update(double t)
{
	//Solo hacemos el update de la escena en la que estamos
	//escenas[actual]->update(t);
	if (niveles[actual]->update(t))	//Si devuelve true es que se han completado los niveles
	{
		completados.insert(actual);
		botones[actual] = completed;
		niveles[NIVELES]->setColors(botones);
		changeScene(NIVELES);
		
	}

	if (completados.size() == niv) {	//Se ha completado el juego

		for (int i = 0; i < niv; i++) botones.push_back(rest);
		niveles[NIVELES]->setColors(botones);
		changeScene(START);

		completados.clear();
	}
}

void GameMachine::changeScene(int s)
{
	if (s != actual) {

		//Ocultamos las particulas de la escena actual
		niveles[actual]->quit();
		//Ponemos en marcha los de la nueva
		niveles[s]->init();
		actual = s;
	}
	
}

void GameMachine::keyPressed(unsigned char key, const physx::PxTransform& camera)
{
	if (actual > niv) {
		changeScene(actual - 1);	//cambiamos al siguiente
	}
	else {
		switch (key)
		{
		case '0':
			std::cout << "---NIVEL FLOTACION---\n";
			changeScene(N_FLOTACION);
			break;
		case '1':
			cout << "---NIVEL VIENTO---\n";
			changeScene(N_VIENTO);
			break;
		case '2':
			cout << "---NIVEL TORNADO---\n";
			changeScene(N_TORNADO);
			break;
		case '3':
			std::cout << "---ESCENA SOLIDOS---\n";
			changeScene(N_SOLIDOS);
			break;
		case '4':
			/*std::cout << "---ESCENA EXPLOSION---\n";
			changeScene(EXPLOSION);*/
			break;
		case '5':
			/*std::cout << "---ESCENA MUELLES---\n";
			changeScene(MUELLES);*/
			break;
		case '6':
			/*std::cout << "---ESCENA ANCLA---\n";
			changeScene(ANCLA);*/
			break;
		case '7':
			/*std::cout << "---ESCENA FLOTACION---\n";
			changeScene(FLOTACION);*/
			break;
		case '8':
			/*std::cout << "---ESCENA SOLIDOS---\n";
			changeScene(SOLIDOS);*/
			break;
		case '9':

			break;

		default:

			niveles[actual]->keyPressed(key, camera);
			break;
		}
	}
}

void GameMachine::shoot(PxVec3 pos)
{
	if (actual >= niv) return;
	niveles[actual]->shoot(pos);
}
