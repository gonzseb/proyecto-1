#include "coleccionMascotas.h"

#include <sstream>
#include <fstream>
#include <string>

coleccionMascotas::coleccionMascotas() : can(0) {
	mascotas = new mascota * [TAM_MAX];
	for (int i = 0; i < TAM_MAX; i++) {
		mascotas[i] = nullptr;
	}
}

coleccionMascotas::~coleccionMascotas() {
	for (int i = 0; i < TAM_MAX; i++) {
		delete mascotas[i];
	}
	delete[] mascotas;
}

int coleccionMascotas::getCan() const { return can; }

bool coleccionMascotas::hayEspacio() const {
	if (can < TAM_MAX) {
		return true;
	}
	else {
		return false;
	}
}

bool coleccionMascotas::existeMascotaPorNombre(string nombre) {
	for (int i = 0; i < can; i++) {
		if (mascotas[i]->getNombre() == nombre) {
			return true;
		}
	}
	return false;
}

void coleccionMascotas::agregarMascota(mascota* mascP) {
	mascotas[can++] = mascP;
}

string coleccionMascotas::toString() const {
	stringstream s;

	s << "  ° Mascotas Registradas °" << endl << endl;
	if (can > 0) {
		for (int i = 0; i < can; i++) {
			s << mascotas[i]->toString() << endl;
			s << "....................................." << endl << endl;
		}
	}

	return s.str();
}

string coleccionMascotas::toStringMascotasPorDueno(dueno* duenoP) {
	stringstream s;

	s << "  ° Mascotas de " << duenoP->getNombre() << " °" << endl << endl;
	if (can > 0) {
		for (int i = 0; i < can; i++) {
			if (mascotas[i]->getDueno() == duenoP) {
				s << " - " << mascotas[i]->getNombre() << endl;
			}
		}
	}

	return s.str();
}

bool coleccionMascotas::hayMascotas() const {
	if (can > 0) {
		return true;
	}
	else {
		return false;
	}
}

mascota* coleccionMascotas::getMascotaPorNombre(string mascotaP) {
	for (int i = 0; i < can; i++) {
		if (mascotas[i]->getNombre() == mascotaP) {
			return mascotas[i];
		}
	}
	return nullptr;
}

bool coleccionMascotas::duenoTieneMascotas(dueno* duenoP) {
	for (int i = 0; i < can; i++) {
		if (mascotas[i]->getDueno() == duenoP) {
			return true;
		}
	}
	return false;
}

bool coleccionMascotas::elDuenoTieneMascotasConCitasRegistradas(dueno* duenoP) {
	for (int i = 0; i < can; i++) {
		if (mascotas[i]->getDueno() == duenoP 
			&& mascotas[i]->getCitasRegistradas() > 0) {
			return true;
		}
	}
	return false;
}

bool coleccionMascotas::guardarDatos() {
	ofstream file1("mascotas.txt");

	if (!file1.is_open()) {
		return false;
	}

	for (int i = 0; i < can; i++) {
		file1 << mascotas[i]->datosFormateados() << endl;
	}
	file1.close();
	return true;
}

bool coleccionMascotas::cargarDatos(coleccionDuenos* coleccionP) {
	ifstream file2("mascotas.txt");

	if (!file2.is_open()) {
		return false;
	}

	string id, nom;
	mascota* mascotaAux = nullptr;
	dueno* duenoAux = nullptr;

	while (getline(file2, id, '\t') && getline(file2, nom)) {
		if (!id.empty() && !nom.empty()) {
			if (can < TAM_MAX && !existeMascotaPorNombre(nom)) {
				duenoAux = coleccionP->getDuenoPorID(id);
				mascotaAux = new mascota(nom, duenoAux);
				agregarMascota(mascotaAux);
			}
		}
	}
	file2.close();
	return true;
}