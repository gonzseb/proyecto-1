#pragma once

#include "especialidad.h"

class coleccionEspecialidades {
private:

	static const int TAM_MAX = 4;
	especialidad** especialidades;
	int can;

public:

	coleccionEspecialidades();
	~coleccionEspecialidades();

	int getCan() const;

	bool hayEspacio() const;
	bool existeEspecialidadPorCodigo(string);
	void agregarEspecialidad(especialidad*);

	especialidad* getEspPorCodigo(string);

	string toString();

	bool hayEspecialidades() const;

	// Persistencia de datos:
	bool guardarDatos();
	bool cargarDatos();

};