#pragma once

#include "dueno.h"

class coleccionDuenos {
private:

	dueno** duenos;
	static const int TAM_MAX = 4;
	int can;

public:

	coleccionDuenos();
	~coleccionDuenos();

	int getCan() const;

	bool hayEspacio() const;
	bool existeDuenoPorID(string);
	void agregarDueno(dueno*);

	dueno* getDuenoPorID(string) const;

	string toString();

	bool hayDuenos() const;

	// Persistencia de datos:
	bool guardarDatos();
	bool cargarDatos();

};