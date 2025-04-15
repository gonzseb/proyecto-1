#include "especialidad.h"

#include <sstream>

especialidad::especialidad(string nom, string cod) 
	: nombre(nom), codigo(cod) {}

especialidad::~especialidad() {}

string especialidad::getNombre() const { return nombre; }

string especialidad::getCodigo() const { return codigo; }

string especialidad::toString() const {
    stringstream s;

    //s << " - Informacion Especialidad" << endl;
    s << "  Especialidad: "  << nombre << endl;
    s << "  Codigo: " << codigo << endl;

    return s.str();
}

string especialidad::datosFormateados() const {
    stringstream s;

    s << codigo << '\t' << nombre;

    return s.str();
}