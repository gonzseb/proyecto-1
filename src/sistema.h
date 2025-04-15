#pragma once

#include "baseDeDatos.h"

class sistema {
private:

	baseDeDatos* baseDeDatos_;

public:

	sistema();
	~sistema();

	// L�gica de los submen�s:
	void mostrarMenuPrincipal();
	void mostrarSubmenuAdministracion();
	void mostrarSubmenuControlCitas();
	void mostrarSubmenuBusquedasYListados();

	// Persistencia de Datos:
	void mostrarSubmenuPersistenciaDeDatos();

};