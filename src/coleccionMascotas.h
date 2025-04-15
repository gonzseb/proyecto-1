#pragma once

#include "mascota.h"
#include "coleccionDuenos.h"

class coleccionMascotas {
private:

	mascota** mascotas;
	static const int TAM_MAX = 16;
	int can;

public:

	coleccionMascotas();
	~coleccionMascotas();

	int getCan() const;

	bool hayEspacio() const;
	bool existeMascotaPorNombre(string);
	void agregarMascota(mascota*);

	mascota* getMascotaPorNombre(string);
	bool duenoTieneMascotas(dueno*);
	bool elDuenoTieneMascotasConCitasRegistradas(dueno*);

	string toString() const;
	string toStringMascotasPorDueno(dueno*);

	bool hayMascotas() const;

	// Persistencia de datos:
	bool guardarDatos();
	bool cargarDatos(coleccionDuenos*);

};