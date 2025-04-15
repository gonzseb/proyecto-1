#pragma once

#include "doctor.h"
#include "coleccionEspecialidades.h"

class coleccionDoctores {
private:

	doctor** doctores;
	static const int TAM_MAX = 4;
	int can;

public:

	coleccionDoctores();
	~coleccionDoctores();

	int getCan() const;

	bool hayEspacio() const;
	bool existeDoctorPorID(string);
	void agregarDoctor(doctor*);

	bool especialidadTieneDoctores(especialidad*);
	doctor* getDoctorPorID(string);
	bool tieneCitasEnElHorarioEscogido(dueno*, int, int);

	string toString();
	string toStringDoctoresPorEspecialidad(especialidad*);
	string toStringMostrarTodasLasCitas();
	string mostrarTodasLasCitasDelDueno(dueno*);

	cita* getCitaDiaYHora(dueno*, int, int);
	void liberarMemoriaCita(cita*, int, int);

	bool hayDoctores() const;

	// Persistencia de datos:
	bool guardarDatos();
	bool cargarDatos(coleccionEspecialidades*);

};