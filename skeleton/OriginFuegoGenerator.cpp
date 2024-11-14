#include "OriginFuegoGenerator.h"

OriginFuegoGenerator::OriginFuegoGenerator(Vector3 o, Vector3 vel, int np)
	:ParticleGenerator(o, vel, np)
{
}

std::vector<Proyectil*> OriginFuegoGenerator::CreateParticles(int actParticles, int maxParticles)
{
	std::vector<Proyectil*> aux;

	if (actParticles == 0) {	//Solo queremos generar particulas de 1 en 1

		color = Vector4(1, 1, 1, 1);
		//Utilizamos la distribucion normal para desviar un poco los fuegos y que no vayan recto
		std::normal_distribution<double> Ndistribution(10.0, 5.0);

		//Quiero cambiar la x y la z de la aceleracion
		Vector3 a;
		double x = Ndistribution(generator);
		double y = Ndistribution(generator);
		double z = Ndistribution(generator);

		color.y = x;

		aux.push_back(new Proyectil(origen, Vector3(0, 50 + y, 0), Vector3(x, 2, z), 0.5, color));
	}

	return aux;
}
