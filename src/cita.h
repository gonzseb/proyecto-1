#pragma once

#include "mascota.h"

class cita {
private:

	mascota* paciente;
	int dia, hora;

public:

	cita(mascota*, int, int);
	~cita();

	mascota* getPaciente() const;
	int getDia() const;
	int getHora() const;

	string toString();

};