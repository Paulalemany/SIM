#pragma once

#include <tgmath.h>

class Vector3D
{

public:

	//Constructora
	Vector3D() {
		x = 0;
		y = 0;
		z = 0;
	}
	Vector3D(double _x, double _y, double _z) {

		x = _x;
		y = _y;
		z = _z;
	}

	//Operaciones
	double Modulo() {

		const double sum = x * x + y * y + z * z;

		return sqrt(sum);
	}

	Vector3D Normalice() {

		const double m = Modulo();

		return Vector3D(x / m, y / m, z / m);
	}

	bool operator==(Vector3D& otro) {

		return x == otro.GetX() && y == otro.GetY() && z == otro.GetZ();
	}

	Vector3D operator=(Vector3D& otro) {
		x = otro.GetX();
		y = otro.GetY();
		z = otro.GetZ();
	}

	Vector3D operator+(Vector3D& otro) {

		return Vector3D(x + otro.GetX(), y + otro.GetY(), z + otro.GetZ());
	}

	Vector3D operator-(Vector3D& otro) {

		return Vector3D(x - otro.GetX(), y - otro.GetY(), z - otro.GetZ());
	}

	//----Multiplicaciones----
	//Producto escalar
	double operator*(Vector3D& otro) {

		return x * otro.GetX() + y * otro.GetY() + z * otro.GetZ();
	}

	//Por un escalar
	double operator*(double escalar) {

		return x * escalar + y * escalar + z * escalar;
	}



	//Getters de las componentes
	double GetX() { return x; }
	double GetY() { return y; }
	double GetZ() { return z; }


private:

	double x, y, z;

};

