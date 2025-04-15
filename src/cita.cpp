#include "cita.h"

#include <sstream>

cita::cita(mascota* mascotaP, int dP, int hP) {
	this->paciente = mascotaP;
	dia = dP;
	hora = hP;
}

cita::~cita() {}

mascota* cita::getPaciente() const { return paciente; }

int cita::getDia() const { return dia; }

int cita::getHora() const { return hora; }

string cita::toString() {
	stringstream s;

	s << paciente->toString() << endl;
	s << " -> Informacion Cita" << endl;
	s << " ° Dia: " << dia << endl;
	s << " ° Hora: " << hora << endl;

	return s.str();
}