#include <iostream>

using namespace std;

static void generarTitulos(string submenu, string tipo) {
	if (!tipo.empty()) {
		cout << '\t' << submenu << " - " << tipo;
	}
	else {
		cout << '\t' << "- " << submenu << " -";
	}
	cout << endl << endl;
}

static void visualMenuPrincipal() {
	generarTitulos("Menu Principal", "");

	cout << "1 - Submenu Administracion" << endl;
	cout << "2 - Submenu Control de Citas" << endl;
	cout << "3 - Submenu Busquedas y Listados" << endl;
	cout << "4 - Submenu Persistencia De Datos" << endl;
	cout << "0 - Salir del sistema" << endl << endl;
}

static void visualsubmenuAdministracion() {
	generarTitulos("Submenu Administracion", "");

	cout << "1 - Ingresar Especialidades" << endl;
	cout << "2 - Ingresar Doctores (por especialidad)" << endl;
	cout << "3 - Ingresar Dueno" << endl;
	cout << "4 - Ingresar Mascota (por dueno)" << endl;
	cout << "0 - Volver a Menu Principal" << endl << endl;
}

static void visualsubmenuControlCitas() {
	generarTitulos("Submenu Control Citas", "");

	cout << "1 - Sacar Cita" << endl;
	cout << "2 - Cancelar Cita" << endl;
	cout << "3 - Mostrar Calendario Citas (por doctor)" << endl;
	cout << "4 - Mostrar Citas (por dueno)" << endl;
	cout << "0 - Volver a Menu Principal" << endl << endl;
}

static void visualsubmenuBusquedasYListados() {
	generarTitulos("Submenu Busquedas Y Listados", "");

	cout << "1 - Mostrar Listado de Especialidades" << endl;
	cout << "2 - Mostrar Listado de Doctores por especialidades" << endl;
	cout << "3 - Mostrar Duenos con sus mascotas" << endl;
	cout << "4 - Mostrar Pacientes (por doctor)" << endl;
	cout << "0 - Volver a Menu Principal" << endl << endl;
}

static void visualsubmenuPersistenciaDeDatos() {
	generarTitulos("Submenu Persistencia De Datos", "");

	cout << "1 - Guardar Especialidades" << endl;
	cout << "2 - Cargar Especialidades" << endl << endl;
	cout << " ..............................." << endl << endl;
	cout << "3 - Guardar Doctores" << endl;
	cout << "4 - Cargar Doctores" << endl << endl;
	cout << " ..............................." << endl << endl;
	cout << "5 - Guardar Duenos" << endl;
	cout << "6 - Cargar Duenos" << endl << endl;
	cout << " ..............................." << endl << endl;
	cout << "7 - Guardar Mascotas" << endl;
	cout << "8 - Cargar Mascotas" << endl;
	cout << " ..............................." << endl << endl;
	cout << "9 - Guardado Rapido" << endl;
	cout << "10 - Cargado Rapido" << endl << endl;
	cout << " ..............................." << endl << endl;
	cout << "0 - Volver a Menu Principal" << endl << endl;
}