#include "sistema.h"

sistema::sistema() {
	baseDeDatos_ = new baseDeDatos();
}

sistema::~sistema() {
	delete baseDeDatos_;
}

// ------------------------------------------------------------------------- //

void sistema::mostrarMenuPrincipal() {
	int opcion;

	do {
		limpiarPantallaPortable();
		visualMenuPrincipal();

		opcion = obtenerOpcion(0, 4);

		switch (opcion) {
		case 0:
			limpiarPantallaPortable();
			cout << "Salida exitosa..." << endl;
			break;
		case 1:
			mostrarSubmenuAdministracion();
			break;
		case 2:
			mostrarSubmenuControlCitas();
			break;
		case 3:
			mostrarSubmenuBusquedasYListados();
			break;
		case 4:
			mostrarSubmenuPersistenciaDeDatos();
			break;
		}

	} while (opcion != 0);
}

void sistema::mostrarSubmenuAdministracion() {
	int opcion;

	do {
		limpiarPantallaPortable();
		visualsubmenuAdministracion();

		opcion = obtenerOpcion(0, 4);

		switch (opcion) {
		case 0:
			break;
		case 1:
			limpiarPantallaPortable();
			baseDeDatos_->ingresarEspecialidades();
			break;
		case 2:
			limpiarPantallaPortable();
			baseDeDatos_->ingresarDoctor();
			break;
		case 3:
			limpiarPantallaPortable();
			baseDeDatos_->ingresarDuenos();
			break;
		case 4:
			limpiarPantallaPortable();
			baseDeDatos_->ingresarMascotas();
			break;
		}

	} while (opcion != 0);
}

void sistema::mostrarSubmenuControlCitas() {
	int opcion;

	do {
		limpiarPantallaPortable();
		visualsubmenuControlCitas();

		opcion = obtenerOpcion(0, 4);

		switch (opcion) {
		case 0:
			break;
		case 1:
			limpiarPantallaPortable();
			baseDeDatos_->sacarCita();
			break;
		case 2:
			limpiarPantallaPortable();
			baseDeDatos_->cancelarCita();
			break;
		case 3:
			limpiarPantallaPortable();
			baseDeDatos_->mostrarCalendarioCitasPorDoctor();
			break;
		case 4:
			limpiarPantallaPortable();
			baseDeDatos_->mostrarCitasPorDueno();
			break;
		}

	} while (opcion != 0);
}

void sistema::mostrarSubmenuBusquedasYListados() {
	int opcion;

	do {
		limpiarPantallaPortable();
		visualsubmenuBusquedasYListados();

		opcion = obtenerOpcion(0, 4);

		switch (opcion) {
		case 0:
			break;
		case 1:
			limpiarPantallaPortable();
			baseDeDatos_->mostrarListadoDeEspecialidades();
			break;
		case 2:
			limpiarPantallaPortable();
			baseDeDatos_->mostrarListadoDeDoctoresPorEspecialidad();
			break;
		case 3:
			limpiarPantallaPortable();
			baseDeDatos_->mostrarDuenosConSusMascotas();
			break;
		case 4:
			limpiarPantallaPortable();
			baseDeDatos_->mostrarPacientesPorDoctor();
			break;
		}

	} while (opcion != 0);
}

// Persistencia de datos:
void sistema::mostrarSubmenuPersistenciaDeDatos() {
	int opcion;

	do {
		limpiarPantallaPortable();
		visualsubmenuPersistenciaDeDatos();

		opcion = obtenerOpcion(0, 10);

		switch (opcion) {
		case 0:
			break;
		case 1:
			limpiarPantallaPortable();
			baseDeDatos_->guardarEspecialidades();
			break;
		case 2:
			limpiarPantallaPortable();
			baseDeDatos_->cargarEspecialidades();
			break;
		case 3:
			limpiarPantallaPortable();
			baseDeDatos_->guardarDoctores();
			break;
		case 4:
			limpiarPantallaPortable();
			baseDeDatos_->cargarDoctores();
			break;
		case 5:
			limpiarPantallaPortable();
			baseDeDatos_->guardarDuenos();
			break;
		case 6:
			limpiarPantallaPortable();
			baseDeDatos_->cargarDuenos();
			break;
		case 7:
			limpiarPantallaPortable();
			baseDeDatos_->guardarMascotas();
			break;
		case 8:
			limpiarPantallaPortable();
			baseDeDatos_->cargarMascotas();
			break;
		case 9:
			baseDeDatos_->guardadoRapidoDeDatos();
			break;
		case 10:
			baseDeDatos_->cargadoRapidoDeDatos();
			break;
		}

	} while (opcion != 0);
}