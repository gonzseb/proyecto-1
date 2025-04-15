#pragma once

#include "visuales.cpp"
#include "utilitarios.cpp"

// Doctores incluye la coleccionEspecialidades:
//#include "coleccionEspecialidades.h"
#include "coleccionDoctores.h"

// Masctoas incluye la coleccionDuenos:
//#include "coleccionDuenos.h"
#include "coleccionMascotas.h"

class baseDeDatos {
	private:

		coleccionEspecialidades* especialidades;
		coleccionDoctores* doctores;
		coleccionDuenos* duenos;
		coleccionMascotas* mascotas;

	public:

		// Inicialización y liberación de las colecciones:
		baseDeDatos();
		~baseDeDatos();

		// Lógica del sistema:
		void ingresarEspecialidades();
		void ingresarDoctor();
		void ingresarDuenos();
		void ingresarMascotas();

		void sacarCita();
		void cancelarCita();
		void mostrarCalendarioCitasPorDoctor();
		void mostrarCitasPorDueno();

		void mostrarListadoDeEspecialidades();
		void mostrarListadoDeDoctoresPorEspecialidad();
		void mostrarDuenosConSusMascotas();
		void mostrarPacientesPorDoctor();

		// Persistencia de Datos:
		void guardarEspecialidades();
		void cargarEspecialidades();
		void guardarDoctores();
		void cargarDoctores();
		void guardarDuenos();
		void cargarDuenos();
		void guardarMascotas();
		void cargarMascotas();
		void guardadoRapidoDeDatos();
		void cargadoRapidoDeDatos();

};