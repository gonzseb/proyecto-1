#include "coleccionDoctores.h"

#include <sstream>
#include <fstream>
#include <string>

coleccionDoctores::coleccionDoctores() {
	doctores = new doctor * [TAM_MAX];
	for (int i = 0; i < TAM_MAX; i++) {
		doctores[i] = nullptr;
	}
	this->can = 0;
}

coleccionDoctores::~coleccionDoctores() {
	for (int i = 0; i < can; i++) {
		delete doctores[i];
	}
	delete[] doctores;
}

int coleccionDoctores::getCan() const { return can; }

bool coleccionDoctores::hayEspacio() const {
	if (can < TAM_MAX) {
		return true;
	}
	else {
		return false;
	}
}

bool coleccionDoctores::existeDoctorPorID(string codP) {
	for (int i = 0; i < can; i++) {
		if (doctores[i]->getID() == codP) {
			return true;
		}
	}
	return false;
}

void coleccionDoctores::agregarDoctor(doctor* docP) {
	// No quiero hacer ninguna validación en este método y explico el porqué:
	// La base de datos se va a encargar de hacer las respetivas validaciones
	// (que haya espacio y que el doctor no esté previamente registrado).
	// Entonces, con fin de ahorrar recursos, este método solo inserta mas no valida,
	// esto es exclusivo de la base de datos.
	// En resumen, para que este método se ejecute, se pasa por un filtro de
	// validaciones previas en la base de datos.
	doctores[can++] = docP; 
}

string coleccionDoctores::toString() {
	stringstream s;

	s << "  ° Doctores Registrados °" << endl << endl;
	if (can > 0) {
		for (int i = 0; i < can; i++) {
			s << doctores[i]->toString() << endl;
		}
	}
	else {
		s << "No hay doctores registrados" << endl;
	}

	return s.str();
}

string coleccionDoctores::toStringDoctoresPorEspecialidad(especialidad* espP) {
	stringstream s;

	s << "  ° Doctores de " << espP->getNombre() << " °" << endl << endl;
	if (can > 0) {
		for (int i = 0; i < can; i++) {
			if (doctores[i]->getEsp() == espP) {
				s << doctores[i]->toString();
			}
		}
	}

	return s.str();
}

string coleccionDoctores::mostrarTodasLasCitasDelDueno(dueno* duenoP) {
	stringstream s;

	for (int i = 0; i < can; i++) {
		if (doctores[i]->tieneCitas()) {
			s << doctores[i]->toStringFiltrarCitasPorDueno(duenoP);
		}
	}

	return s.str();
}

cita* coleccionDoctores::getCitaDiaYHora(dueno* duenoP, int diaP, int horaP) {
	// Recorrer todos los doctores en la colección
	for (int i = 0; i < can; i++) {
		// Obtener la cita en el día y hora especificados
		cita* citaEncontrada = doctores[i]->getCitaPorDiaYHora(diaP, horaP);

		// Verificar si la cita pertenece al dueño buscado
		if (citaEncontrada != nullptr && citaEncontrada->getPaciente()->getDueno() == duenoP) {
			return citaEncontrada; // Retornar la cita encontrada
		}
	}
	return nullptr; // Si no se encuentra la cita, retornar nullptr
}

void coleccionDoctores::liberarMemoriaCita(cita* citaP, int diaP, int horaP) {
	for (int i = 0; i < can; i++) {
		if (doctores[i]->tieneCitas() && doctores[i]->getCitaPorDiaYHora(diaP, horaP) == citaP) {
			doctores[i]->liberarMemoria(citaP, diaP, horaP);
		}
	}
}

bool coleccionDoctores::hayDoctores() const {
	if (can > 0) {
		return true;
	}
	else {
		return false;
	}
}

string coleccionDoctores::toStringMostrarTodasLasCitas() {
	stringstream s;
	for (int i = 0; i < can; i++) {
		if (doctores[i]->tieneCitas()) {
			s << doctores[i]->toString() << endl;
		}
	}
	return s.str();
}

bool coleccionDoctores::especialidadTieneDoctores(especialidad* espP) {
	for (int i = 0; i < can; i++) {
		if (doctores[i]->getEsp() == espP) {
			return true;
		}
	}
	return false;
}

doctor* coleccionDoctores::getDoctorPorID(string idP) {
	for (int i = 0; i < can; i++) {
		if (doctores[i]->getID() == idP) {
			return doctores[i];
		}
	}
	return nullptr;
}

bool coleccionDoctores::tieneCitasEnElHorarioEscogido(dueno* duenoP, int dia, int hora) {
	for (int i = 0; i < can; i++) {
		if (doctores[i]->tieneCitaEnElHorario(duenoP, dia, hora)) {
			return true;
		}
	}
	return false;
}

bool coleccionDoctores::guardarDatos() {
	ofstream file1("doctores.txt");

	if (!file1.is_open()) {
		return false;
	}

	for (int i = 0; i < can; i++) {
		file1 << doctores[i]->datosFormateados() << endl;
	}
	file1.close();
	return true;
}

bool coleccionDoctores::cargarDatos(coleccionEspecialidades* coleccionP) {
	ifstream file2("doctores.txt");

	if (!file2.is_open()) {
		return false;
	}

	string codEsp, id, nom;
	doctor* docAux = nullptr;
	especialidad* espAux = nullptr;

	while (getline(file2, codEsp, '\t') && getline(file2, id, '\t') && getline(file2, nom)) {
		if (!codEsp.empty() && !id.empty() && !nom.empty()) {
			if (can < TAM_MAX && !existeDoctorPorID(id)) {
				espAux = coleccionP->getEspPorCodigo(codEsp);
				docAux = new doctor(nom, id, espAux);
				agregarDoctor(docAux);
			}
		}
	}
	file2.close();
	return true;
}