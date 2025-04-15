#include "dueno.h"

#include <sstream>

dueno::dueno(string nombre, string id) : nombre(nombre), id(id) {}

string dueno::getNombre() const { return nombre; }

string dueno::getID() const { return id; }

string dueno::toString() const {
	stringstream s;
	s << " - Informacion Dueno" << endl;
	s << " Nombre ... " << nombre << endl;;
	s << " ID ... " << id << endl;
	return s.str();
}

string dueno::datosFormateados() const {
	stringstream s;
	s << id << '\t' << nombre;
	return s.str();
}