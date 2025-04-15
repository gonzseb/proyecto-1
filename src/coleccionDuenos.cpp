#include "coleccionDuenos.h"

#include <sstream>
#include <fstream>
#include <string>

coleccionDuenos::coleccionDuenos() : can(0) {
	duenos = new dueno * [TAM_MAX];
	for (int i = 0; i < TAM_MAX; i++) {
		duenos[i] = nullptr;
	}
}

coleccionDuenos::~coleccionDuenos() {
	for (int i = 0; i < can; i++) {
		delete duenos[i];
	}
	delete[] duenos;
}

int coleccionDuenos::getCan() const { return can; }

bool coleccionDuenos::hayEspacio() const {
	if (can < TAM_MAX) {
		return true;
	}
	else {
		return false;
	}
}

bool coleccionDuenos::existeDuenoPorID(string idP) {
	for (int i = 0; i < can; i++) {
		if (duenos[i]->getID() == idP) {
			return true;
		}
	}
	return false;
}

void coleccionDuenos::agregarDueno(dueno* duenoP) {
	duenos[can++] = duenoP;
}

dueno* coleccionDuenos::getDuenoPorID(string idP) const {
	for (int i = 0; i < can; i++) {
		if (duenos[i]->getID() == idP) {
			return duenos[i];
		}
	}
	return nullptr;
}

string coleccionDuenos::toString() {
	stringstream s;

	s << "  ° Duenos Registrados °" << endl << endl;
	if (can > 0) {
		for (int i = 0; i < can; i++) {
			s << duenos[i]->toString() << endl;
		}
	}
	else {
		s << "No hay duenos registrados" << endl;
	}

	return s.str();
}

bool coleccionDuenos::hayDuenos() const {
	if (can > 0) {
		return true;
	}
	else {
		return false;
	}
}

bool coleccionDuenos::guardarDatos() {
	ofstream file1("duenos.txt");

	if (!file1.is_open()) {
		return false;
	}

	for (int i = 0; i < can; i++) {
		file1 << duenos[i]->datosFormateados() << endl;
	}
	file1.close();
	return true;
}

bool coleccionDuenos::cargarDatos() {
	ifstream file2("duenos.txt");

	if (!file2.is_open()) {
		return false;
	}

	string id, nom;
	dueno* duenoAux = nullptr;

	while (getline(file2, id, '\t') && getline(file2, nom)) {
		if (!id.empty() && !nom.empty()) {
			if (can < TAM_MAX && !existeDuenoPorID(id)) {
				duenoAux = new dueno(nom, id);
				agregarDueno(duenoAux);
			}
		}
	}
	file2.close();
	return true;
}