#include "coleccionEspecialidades.h"

#include <sstream>
#include <fstream>
#include <string>

coleccionEspecialidades::coleccionEspecialidades() {
	especialidades = new especialidad * [TAM_MAX];
	for (int i = 0; i < TAM_MAX; i++) {
		especialidades[i] = nullptr;
	}
	this->can = 0;
}

coleccionEspecialidades::~coleccionEspecialidades() {
	for (int i = 0; i < can; i++) {
		delete especialidades[i];
	}
	delete[] especialidades;
}

int coleccionEspecialidades::getCan() const { return can; }

bool coleccionEspecialidades::hayEspacio() const {
	if (can < TAM_MAX) {
		return true;
	}
	else {
		return false;
	}
}

bool coleccionEspecialidades::existeEspecialidadPorCodigo(string codP) {
	for (int i = 0; i < can; i++) {
		if (especialidades[i]->getCodigo() == codP) {
			return true;
		}
	}
	return false;
}

void coleccionEspecialidades::agregarEspecialidad(especialidad* esp) {
	especialidades[can++] = esp;
}

especialidad* coleccionEspecialidades::getEspPorCodigo(string codP) {
	for (int i = 0; i < can; i++) {
		if (especialidades[i]->getCodigo() == codP) {
			return especialidades[i];
		}
	}
	return nullptr;
}

string coleccionEspecialidades::toString() {
	stringstream s;

	s << "  ° Especialidades Registradas °" << endl << endl;
	if (can > 0) {
		for (int i = 0; i < can; i++) {
			s << especialidades[i]->toString() << endl;
		}
	}

	return s.str();
}

bool coleccionEspecialidades::hayEspecialidades() const {
	if (can > 0) {
		return true;
	}
	else {
		return false;
	}
}

bool coleccionEspecialidades::guardarDatos() {
	ofstream file1("especialidades.txt");

	if (!file1.is_open()) {
		return false;
	}

	for (int i = 0; i < can; i++) {
		file1 << especialidades[i]->datosFormateados() << endl;
	}
	file1.close();
	return true;
}

bool coleccionEspecialidades::cargarDatos() {
	ifstream file2("especialidades.txt");

	if (!file2.is_open()) {
		return false;
	}

	string cod, nom;
	especialidad* espAux = nullptr;

	while (getline(file2, cod, '\t') && getline(file2, nom)) {
		if (!cod.empty() && !nom.empty()) {
			if (can < TAM_MAX && !existeEspecialidadPorCodigo(cod)) {
				espAux = new especialidad(nom, cod);
				agregarEspecialidad(espAux);
			}
		}
	}
	file2.close();
	return true;
}