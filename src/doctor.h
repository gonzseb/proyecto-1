#pragma once

#include "especialidad.h"
#include "cita.h"

class doctor {
private:

        string nombre;
        string id;
        especialidad* esp;

        static const int FILAS = 6;
        static const int COLUMNAS = 11;
        cita*** agendaCitas;
        int canCitas;

public:

    doctor(string, string, especialidad*);
    ~doctor();

    void setEsp(especialidad*);

    string getID() const;
    especialidad* getEsp() const;

    string toString() const;

    // Administracion de la agenda del doctor:
    string toStringAgendaCitas();
    bool hayEspacio() const;
    bool estaOcupado(int, int);
    void agregarCita(int, int, cita*);

    bool tieneCitas() const;
    bool tieneCitaEnElHorario(dueno*, int, int);

    string toStringFiltrarCitasPorDueno(dueno*);
    string toStringPacientesDelDoctor();
    cita* getCitaPorDiaYHora(int, int);
    void liberarMemoria(cita*, int, int);

    // Persistencia de datos:
    string datosFormateados() const;

};