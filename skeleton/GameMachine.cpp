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
	escenas.push_back(new MuellesScene());
	escenas.push_back(new AnclaScene());
	escenas.push_back(new FlotacionScene());
	escenas.push_back(new SolidScene(s, p));
	actual = SOLIDOS;	//Escena con la que iniciamos

	//Escondemos todas las que no sean la escena actual
	for (int i = 0; i < escenas.size(); i++) {
		if (i != actual) escenas[i]->quit();
	}

	//Vamos a hacer esto un poco de mala manera para testear

	target = new SolidoRigido();
	target->CreateStatic(s, p, { 20, 0, -0.5 }, { 2, 2, 2 }, { 0, 0, 0, 1 });
}

GameMachine::~GameMachine()
{
}

void GameMachine::update(double t)
{
	//Solo hacemos el update de la escena en la que estamos
	escenas[actual]->update(t);

	if (bullet != nullptr) {
		bullet->update(t);

		if (target->inBoundingBox(bullet->getPosition())) ;	//Aqui simplemente poner la condicion de victoria
	}
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


		///Input para cambiar la bala
	case 's':
		std::cout << "---BALA PEQUE�A---\n";
		bulletColor = { 0, 0, 1, 1 };
		bulletMasa = 1;
		bulletTam = 0.5;
		break;
	case 'm':
		std::cout << "---BALA MEDIANA---\n";
		bulletColor = { 1, 0, 0, 1 };
		bulletMasa = 10;
		bulletTam = 1;
		break;
	case 'l':
		std::cout << "---BALA GRANDE---\n";
		bulletColor = { 0, 1, 0, 1 };
		bulletMasa = 100;
		bulletTam = 2;
		break;

	default:

		escenas[actual]->keyPressed(key, camera);
		break;
	}

}

void GameMachine::shoot(PxVec3 pos)
{
	if (bullet != nullptr) bullet->~Particle();

	//La direccion es el vector que hay entre el punto pos y el origen
	PxVec3 ori = {-20, 0, 0};
	PxVec3 dir = (pos - ori).getNormalized();
	bullet = new Proyectil(ori, dir * 40, { 0,0,0 }, 0.5, bulletColor);

	//Estas dos cosas y el color es lo que deberia variar con cada tipo de bala
	bullet->setMasa(bulletMasa);
	bullet->setTam(bulletTam, 0);
}
