#pragma once

#include "dueno.h"

class mascota {
private:

	string nombre;
	dueno* _dueno;
	int citasRegistradas;

public:

	mascota(string, dueno*);
	~mascota();

	void setDueno(dueno*);

	string getNombre() const;
	dueno* getDueno() const;

	void agregarCita();
	void decrementarCitas();
	int getCitasRegistradas() const;

	string toString();

	// Persistencia de datos:
	string datosFormateados() const;

};