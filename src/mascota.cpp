#include "mascota.h"

#include <sstream>

mascota::mascota(string nomP, dueno* duenP) {
	this->nombre = nomP;
	this->_dueno = duenP;
	this->citasRegistradas = 0;
}

mascota::~mascota() {}

void mascota::setDueno(dueno* duenoP) { this->_dueno = duenoP; }

string mascota::getNombre() const { return nombre; }

dueno* mascota::getDueno() const { return _dueno; }

void mascota::agregarCita() { citasRegistradas++; }

void mascota::decrementarCitas() { citasRegistradas--; }

int mascota::getCitasRegistradas() const { return citasRegistradas; }

string mascota::toString() {
	stringstream s;

	s << " - Informacion Mascota" << endl;
	s << " Nombre ... " << nombre << endl << endl;
	s << _dueno->toString();

	return s.str();
}

string mascota::datosFormateados() const {
	stringstream s;

	s << _dueno->getID() << '\t' << nombre;

	return s.str();
}