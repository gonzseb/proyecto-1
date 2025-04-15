#pragma once

#include <string>

using namespace std;

class dueno {
private:

	string nombre, id;

public:

	dueno(string, string);

	string getNombre() const;
	string getID() const;

	string toString() const;

	// Persistencia de datos:
	string datosFormateados() const;

};