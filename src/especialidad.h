#pragma once

#include <string>

using namespace std;

class especialidad {
private:

	string nombre, codigo;

public:

	especialidad(string, string);
	~especialidad();

	string getNombre() const;
	string getCodigo() const;

	string toString() const;

	// Persistencia de datos:
	string datosFormateados() const;

};