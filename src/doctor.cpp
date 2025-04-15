#include "doctor.h"

#include <sstream>

doctor::doctor(string nombre, string id, especialidad* esp) 
    : nombre(nombre), id(id), esp(esp) {
    // Crear un array dinámico de punteros a punteros (filas de la matriz):
    agendaCitas = new cita * *[FILAS];

    // Para cada fila, crear un array dinámico de punteros (columnas):
    for (int i = 0; i < FILAS; i++) {
        agendaCitas[i] = new cita * [COLUMNAS];
    }

    // Inicializar cada celda de la matriz con nullptr (sin objetos aún):
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            agendaCitas[i][j] = nullptr;
        }
    }
    this->canCitas = 0;
}

doctor::~doctor() {
    // Recorrer cada celda de la matriz:
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            // Si la celda tiene un objeto, liberar la memoria del objeto:
            if (agendaCitas[i][j]) {
                delete agendaCitas[i][j];
            }
        }
    }

    // Liberar la memoria de cada fila (array de columnas):
    for (int i = 0; i < FILAS; i++) {
        delete[] agendaCitas[i];
    }

    // Liberar la memoria del array principal (filas):
    delete[] agendaCitas;
}

void doctor::setEsp(especialidad* espP) {
    this->esp = espP;
}

string doctor::getID() const { return id; }

especialidad* doctor::getEsp() const {
    return esp;
}

string doctor::toString() const {
    stringstream s;

    s << " - Informacion Doctor" << endl;
    s << " Nombre ... " << nombre << endl;
    s << " ID ... " << id << endl;
    s << esp->toString() << endl;

    return s.str();
}

string doctor::toStringFiltrarCitasPorDueno(dueno* duenoP) {
    stringstream s;

    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (agendaCitas[i][j] != nullptr &&
                agendaCitas[i][j]->getPaciente()->getDueno() == duenoP) {
                s << " --------------------------------------- " << endl;
                s << "\t   Cita Registrada " << endl;
                s << " --------------------------------------- " << endl;
                s << agendaCitas[i][j]->toString() << endl;
            }
        }
    }

    return s.str();
}

string doctor::toStringPacientesDelDoctor() {
    stringstream s;

    s << "  ° Pacientes del doctor °" << endl << endl;
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (agendaCitas[i][j] != nullptr) {
                s << agendaCitas[i][j]->getPaciente()->toString() << endl;
                s << "----------------------------------" << endl << endl;
            }
        }
    }

    return s.str();
}

cita* doctor::getCitaPorDiaYHora(int dia, int hora) {
    return agendaCitas[dia][hora];
}

void doctor::liberarMemoria(cita* citaP, int dia, int hora) {
    canCitas--;
    citaP->getPaciente()->decrementarCitas();
    agendaCitas[dia][hora] = nullptr;
    delete citaP;
}

string doctor::toStringAgendaCitas() {
    stringstream s;

    // Cabecera de la tabla:
    s << " Horario | Lunes      | Martes     | Miercoles  | Jueves     | Viernes     | Sabado      " << endl;
    s << "----------------------------------------------------------------------------------------" << endl;

    // Iterar por cada hora (fila):
    for (int i = 0; i < COLUMNAS; i++) { // Cambiar a COLUMNAS para iterar correctamente por las horas
        // Convertir la hora de la fila a formato 24h
        int horaInicio = 8 + i; // Asumiendo que las horas comienzan a las 8 AM y terminan a las 19 PM
        if (horaInicio < 10) {
            s << "  0";
        }
        else {
            s << "  ";
        }
        s << horaInicio << ":00  |";
        //s << (horaInicio < 10 ? "0" : "") << horaInicio << ":00    |";

        // Iterar por cada día (columna)
        for (int j = 0; j < FILAS; j++) { // Cambiar a FILAS para iterar correctamente por los días
            if (agendaCitas[j][i]) { // Cambiar índices para acceder correctamente a la matriz
                s << " Ocupado    |";
            }
            else {
                s << " Libre      |";
            }
        }
        s << endl; // Nueva línea al final de cada fila
    }
    s << endl;

    return s.str();
}

bool doctor::hayEspacio() const {
    if (canCitas < (FILAS*COLUMNAS)) {
        return true;
    }
    return false;
}

bool doctor::estaOcupado(int diaP, int horaP) {
    if (agendaCitas[diaP][horaP]) {
        return true;
    }
    return false;
}

void doctor::agregarCita(int diaP, int horaP, cita* citaP) {
    agendaCitas[diaP][horaP] = citaP;
    citaP->getPaciente()->agregarCita();
    canCitas++;
}

bool doctor::tieneCitas() const {
    if (canCitas > 0) {
        return true;
    }
    return false;
}

bool doctor::tieneCitaEnElHorario(dueno* duenoP, int dia, int hora) {
    if (agendaCitas[dia][hora] != nullptr &&
        agendaCitas[dia][hora]->getPaciente()->getDueno() == duenoP) {
        return true;
    }
    return false;
}

string doctor::datosFormateados() const {
    stringstream s;

    s << esp->getCodigo() << '\t' << id << '\t' << nombre;

    return s.str();
}