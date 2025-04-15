#include "baseDeDatos.h"

baseDeDatos::baseDeDatos() {
    especialidades = new coleccionEspecialidades();
    doctores = new coleccionDoctores();
    duenos = new coleccionDuenos();
    mascotas = new coleccionMascotas();
}

baseDeDatos::~baseDeDatos() {
	delete especialidades;
    delete doctores;
    delete duenos;
    delete mascotas;
}

// ------------------------------------------------------------------------- //

void baseDeDatos::ingresarEspecialidades() {
    int opcion;

    do {
        generarTitulos("Administracion", "Ingresar Especialidad");

        // Validar capacidad del vector especialidades:
        if (!especialidades->hayEspacio()) {
            cout << "Error: No hay espacio para ingresar mas especialidades. Digite 0 para salir." << endl;
            opcion = obtenerOpcion(0, 0);
            break;
        }

        // Se pide el codigo de la nueva especialidad y se valida:
        string cod = obtenerEntrada("Ingrese el codigo de la especialidad (sin espacios): ");

        if (especialidades->existeEspecialidadPorCodigo(cod)) {
            cout << "Error: La especialidad ya esta ingresada. Digite 0 para salir." << endl << endl;
            opcion = obtenerOpcion(0, 0);
            break;
        }

        // Se sigue el proceso si se valido correctamente:
        string nom = obtenerEntrada("Ingrese el nombre de la especialidad: ");

        // Se crea una nueva especialidad con los datos obtenidos:
        especialidad* nuevaEspecialidad = new especialidad(nom, cod);
        especialidades->agregarEspecialidad(nuevaEspecialidad);
        cout << "Se ha ingresado la especialidad con exito." << endl << endl;

        // Opción de continuación:
        cout << "Digite 1 para ingresar mas especialidades, o digite 0 para salir." << endl;
        opcion = obtenerOpcion(0, 1);
        limpiarPantallaPortable();

    } while (opcion != 0);
}

void baseDeDatos::ingresarDoctor() {
    int opcion;

    do {
        generarTitulos("Administracion", "Ingresar Doctor");

        // Validar que hayan especialidades ingresadas:
        if (!especialidades->hayEspecialidades()) {
            cout << "Error: No hay especialidades ingresadas. Digite 0 para salir." << endl;
            opcion = obtenerOpcion(0, 0);
            break;
        }

        // Validar capacidad del vector doctores:
        if (!doctores->hayEspacio()) {
            cout << "Error: No hay espacio para mas doctores. Digite 0 para salir." << endl;
            opcion = obtenerOpcion(0, 0);
            break;
        }

        // Se piden el ID del nuevo doctor y se valida:
        string id = obtenerEntrada("Ingrese el ID del doctor (sin espacios): ");

        if (doctores->existeDoctorPorID(id)) {
            cout << "Error: El doctor ya esta ingresado. Digite 0 para salir." << endl << endl;
            opcion = obtenerOpcion(0, 0);
            break;
        }

        // Se sigue el proceso si se valido correctamente:
        string nom = obtenerEntrada("Ingrese el nombre del doctor: ");
        doctor* nuevoDoctor = new doctor(nom, id, nullptr);

        // Mostrar las especialidades ingresadas:
        cout << especialidades->toString();

        // Selección de la especialidad...
        especialidad* espEncontrada;
        do {
            // Se pide el codigo de una especialidad mostrada:
            string espCod = obtenerEntrada("Digite el codigo de la especialidad del doctor (sin espacios): ");

            // Se obtiene la especialidad:
            espEncontrada = especialidades->getEspPorCodigo(espCod);

            // Si no existe la especialidad ingresada, error:
            if (espEncontrada == nullptr) {
                cout << "Error: El codigo no existe. Por favor, indique un codigo valido." << endl << endl;
            }

        } while (espEncontrada == nullptr); // Repetir hasta que se obtenga una especialidad ingresada.

        // Se le asigna la especialidad al nuevo doctor:
        nuevoDoctor->setEsp(espEncontrada);
        // Se ingresa el nuevo doctor al arreglo:
        doctores->agregarDoctor(nuevoDoctor);
        cout << "Doctor agregado correctamente a la especialidad." << endl << endl;

        cout << "Digite 1 para continuar agregando doctores, o digite 0 para salir." << endl;
        opcion = obtenerOpcion(0, 1);
        limpiarPantallaPortable();

    } while (opcion != 0);
}

void baseDeDatos::ingresarDuenos() {
    int opcion;

    do {
        generarTitulos("Administracion", "Ingresar Dueno");

        // Validar capacidad del vector duenos:
        if (!duenos->hayEspacio()) {
            cout << "Error: No hay espacio para ingresar mas duenos. Digite 0 para salir." << endl;
            opcion = obtenerOpcion(0, 0);
            break;
        }

        // Se pide el codigo del nuevo dueno y se valida:
        string cod = obtenerEntrada("Ingrese el ID del dueno (sin espacios): ");

        if (duenos->existeDuenoPorID(cod)) {
            cout << "Error: El dueno ya esta ingresado. Digite 0 para salir." << endl << endl;
            opcion = obtenerOpcion(0, 0);
            break;
        }

        // Se sigue el proceso si se valido correctamente:
        string nom = obtenerEntrada("Ingrese el nombre del dueno: ");

        // Se crea un nuevo dueno con los datos obtenidos:
        dueno* nuevoDueno = new dueno(nom, cod);
        duenos->agregarDueno(nuevoDueno);
        cout << "Se ha ingresado el dueno con exito." << endl << endl;

        // Opción de continuación:
        cout << "Digite 1 para ingresar mas duenos, o digite 0 para salir." << endl;
        opcion = obtenerOpcion(0, 1);
        limpiarPantallaPortable();

    } while (opcion != 0);;
}

void baseDeDatos::ingresarMascotas() {
    int opcion;

    do {
        generarTitulos("Administracion", "Ingresar Mascota");

        // Validar que hayan duenos ingresados:
        if (!duenos->hayDuenos()) {
            cout << "Error: No hay duenos ingresados. Digite 0 para salir." << endl;
            opcion = obtenerOpcion(0, 0);
            break;
        }

        // Validar capacidad del vector mascotas:
        if (!mascotas->hayEspacio()) {
            cout << "Error: No hay espacio para mas mascotas. Digite 0 para salir." << endl;
            opcion = obtenerOpcion(0, 0);
            break;
        }

        // Se piden el nombre de la nueva mascota y se valida:
        string nom = obtenerEntrada("Ingrese el nombre de la mascota: ");

        if (mascotas->existeMascotaPorNombre(nom)) {
            cout << "Error: La mascota ya esta ingresada. Digite 0 para salir." << endl << endl;
            opcion = obtenerOpcion(0, 0);
            break;
        }

        // Se sigue el proceso si se valido correctamente:
        mascota* nuevaMascota = new mascota(nom, nullptr);

        // Mostrar las especialidades ingresadas:
        cout << duenos->toString();

        // Selección del dueno...
        dueno* duenoEncontrado;
        do {
            // Se pide el ID de un dueno mostrado:
            string duenoID = obtenerEntrada("Digite el ID del dueno (sin espacios): ");

            // Se obtiene el dueno:
            duenoEncontrado = duenos->getDuenoPorID(duenoID);

            // Si no existe la especialidad ingresada, error:
            if (duenoEncontrado == nullptr) {
                cout << "Error: El ID no existe. Por favor, indique un ID valido." << endl << endl;
            }

        } while (duenoEncontrado == nullptr); // Repetir hasta que se obtenga un dueno ingresado.

        // Se le asigna el dueno a la nueva mascota:
        nuevaMascota->setDueno(duenoEncontrado);
        // Se ingresa la nueva mascota al arreglo:
        mascotas->agregarMascota(nuevaMascota);
        cout << "Mascota agregada correctamente al dueno." << endl << endl;

        cout << "Digite 1 para continuar agregando mascotas, o digite 0 para salir." << endl;
        opcion = obtenerOpcion(0, 1);
        limpiarPantallaPortable();

    } while (opcion != 0);
}

void baseDeDatos::sacarCita(){
    int opcion;

    do {
        generarTitulos("Administracion", "Ingresar Cita");

        // Validar que existan especialidades, doctores, duenos y mascotas:
        if (!especialidades->hayEspecialidades() || !doctores->hayDoctores() ||
            !duenos->hayDuenos() || !mascotas->hayMascotas()) {
            cout << "Error: Asegurese de ingresar especialidades, doctores, duenos y mascotas. Digite 0 para salir." << endl;
            opcion = obtenerOpcion(0, 0);
            break;
        }

        // Pedir ID del dueno:
        string id = obtenerEntrada("Digite el ID del dueno: ");

        // Validar existencia del dueno:
        if (!duenos->existeDuenoPorID(id)) {
            cout << "Error: El dueno no ha sido ingresado. Digite 0 para salir." << endl;
            opcion = obtenerOpcion(0, 0);
            break;
        }

        // Se obtiene el dueno:
        dueno* duenoObtenido = duenos->getDuenoPorID(id);

        // Validar que hayan mascotas con un puntero a ese dueno obtenido:
        if (!mascotas->duenoTieneMascotas(duenoObtenido)) {
            cout << "Error: El dueno no tiene mascotas. Digite 0 para salir." << endl;
            opcion = obtenerOpcion(0, 0);
            break;
        }

        // Se muestran las mascotas que apunten a ese dueno:
        cout << mascotas->toStringMascotasPorDueno(duenoObtenido) << endl;

        // Obtener una mascota:
        mascota* mascotaObtenida;
        do {
            // Se pide el nombre de una mascota mostrada:
            string nombreMascota = obtenerEntrada("Digite el nombre de la mascota: ");

            // Se obtiene el dueno:
            mascotaObtenida = mascotas->getMascotaPorNombre(nombreMascota);

            // Si no existe la mascota ingresada, error:
            if (mascotaObtenida == nullptr) {
                cout << "Error: La mascota ingresada no existe. Por favor, indique un nombre valido." << endl << endl;
            }
        } while (mascotaObtenida == nullptr);

        // Mostrar las especialidades registradas:
        cout << especialidades->toString();

        // Solicitar una especialidad de las mostradas:
        string codEsp = obtenerEntrada("Ingrese el codigo de la especialidad: ");

        // Validar especialidad existente:
        if (!especialidades->existeEspecialidadPorCodigo(codEsp)) {
            cout << "Error: La especialidad ingresada no existe. Digite 0 para salir." << endl;
            opcion = obtenerOpcion(0, 0);
            break;
        }

        // Obtener especialidad:
        especialidad* espObtenida = especialidades->getEspPorCodigo(codEsp);

        // Validar que al menos un doctor apunte a esa especialidad:
        if (!doctores->especialidadTieneDoctores(espObtenida)) {
            cout << "Error: La especialidad no tiene doctores. Digite 0 para salir." << endl;
            opcion = obtenerOpcion(0, 0);
            break;
        }

        // Motrar los doctores que apuntan a esa especialidad:
        cout << doctores->toStringDoctoresPorEspecialidad(espObtenida);

        // Obtener un doctor de los mostrados:
        doctor* doctorObtenido;
        do {
            // Se pide el id de un doctor mostrado:
            string idDoc = obtenerEntrada("Digite el ID del doctor: ");

            // Se obtiene el doc:
            doctorObtenido = doctores->getDoctorPorID(idDoc);

            // Si no existe el doctor ingresado, error:
            if (doctorObtenido == nullptr) {
                cout << "Error: El doctor ingresado no existe. Por favor, indique un nombre valido." << endl << endl;
            }
        } while (doctorObtenido == nullptr);

        // Validar que ese doctor tenga espacio en su agenda:
        if (!doctorObtenido->hayEspacio()) {
            cout << "Error: La agenda del doctor alcanzo su capacidad maxima. Digite 0 para salir." << endl;
            opcion = obtenerOpcion(0, 0);
            break;
        }

        // Mostrar agenda del doctor:
        cout << doctorObtenido->toStringAgendaCitas();

        // Validar que el paciente no tenga citas con otros doctores o 
        // con el mismo en el mismo horario y validar un horario de doctor no ocupado:
        bool esValido;
        int dia, hora;

        do {
            cout << "Ingrese un dia para la cita (0: Lunes, 1: Martes, ..., 5: Sabado): ";
            dia = obtenerOpcion(0, 5);
            cout << endl;

            cout << "Ingrese una hora para la cita (0 para 8:00, 1 para 9:00, ..., 10 para 19:00): ";
            hora = obtenerOpcion(0, 10);
            cout << endl;

            if (doctores->tieneCitasEnElHorarioEscogido(duenoObtenido, dia, hora)) {
                esValido = false;
                cout << "Error: Ya tiene una cita registrada a esta hora. Digite un dia y hora validos." << endl << endl;
            }
            else if (doctorObtenido->estaOcupado(dia, hora)) {
                esValido = false;
                cout << "Error: El dia y la hora escogidos estan ocupados. Digite un dia y hora validos." << endl << endl;
            }
            else {
                esValido = true;
            }

        } while (esValido == false);

        // Generar nueva cita:
        cita* nuevaCita = new cita(mascotaObtenida, dia, hora);
        doctorObtenido->agregarCita(dia, hora, nuevaCita);
        cout << "Cita agregada correctamente." << endl << endl;

        // Opción de continuación:
        cout << "Digite 1 para continuar agregando citas, o digite 0 para salir." << endl;
        opcion = obtenerOpcion(0, 1);
        limpiarPantallaPortable();

    } while (opcion != 0);
}

void baseDeDatos::cancelarCita() {
    int opcion;

    do {
        generarTitulos("Administracion", "Cancelar Cita");

        // Validar que existan especialidades, doctores, duenos y mascotas:
        if (!especialidades->hayEspecialidades() || !doctores->hayDoctores() ||
            !duenos->hayDuenos() || !mascotas->hayMascotas()) {
            cout << "Error: Asegurese de ingresar especialidades, doctores, duenos y mascotas. Digite 0 para salir." << endl;
            opcion = obtenerOpcion(0, 0);
            break;
        }

        // Pedir ID del dueno:
        string id = obtenerEntrada("Digite el ID del dueno: ");

        // Validar existencia del dueno:
        if (!duenos->existeDuenoPorID(id)) {
            cout << "Error: El dueno no ha sido ingresado. Digite 0 para salir." << endl;
            opcion = obtenerOpcion(0, 0);
            break;
        }

        // Se obtiene el dueno:
        dueno* duenoObtenido = duenos->getDuenoPorID(id);

        // Validar que hayan mascotas con apuntando a ese dueno obtenido:
        if (!mascotas->duenoTieneMascotas(duenoObtenido)) {
            cout << "Error: El dueno no tiene mascotas. Digite 0 para salir." << endl;
            opcion = obtenerOpcion(0, 0);
            break;
        }

        // Validar que el dueno tenga mascotas con citas registradas:
        if (!mascotas->elDuenoTieneMascotasConCitasRegistradas(duenoObtenido)) {
            cout << "Error: Las mascotas del dueno no tienen citas registradas. Digite 0 para salir." << endl;
            opcion = obtenerOpcion(0, 0);
            break;
        }

        // Filtrar las citas correpondientes al dueno:
        cout << doctores->mostrarTodasLasCitasDelDueno(duenoObtenido);

        // Validar que se ingrese una cita de las existentes:
        cita* citaObtenida;
        int dia, hora;

        do {
            cout << "Ingrese un dia asignado (0: Lunes, 1: Martes, ..., 5: Sabado): ";
            dia = obtenerOpcion(0, 5);
            cout << endl;

            cout << "Ingrese una hora asignada (0 para 8:00, 1 para 9:00, ..., 10 para 19:00): ";
            hora = obtenerOpcion(0, 10);
            cout << endl;

            citaObtenida = doctores->getCitaDiaYHora(duenoObtenido, dia, hora);

            if (citaObtenida == nullptr) {
                cout << "Error: Ingrese una cita valida. Intente de nuevo." << endl << endl;
            }

        } while (citaObtenida == nullptr);

        cout << " ------ !Cita Eliminada -----" << endl << endl;
        cout << citaObtenida->toString() << endl;
        cout << " ----------------------------" << endl << endl;

        doctores->liberarMemoriaCita(citaObtenida, dia, hora);
        cout << "Se ha cancelado la cita correctamente" << endl << endl;

        // Opción de continuación:
        cout << "Digite 1 para seguir cancelando citas, o digite 0 para salir." << endl;
        opcion = obtenerOpcion(0, 1);
        limpiarPantallaPortable();

    } while (opcion != 0);
}

void baseDeDatos::mostrarCalendarioCitasPorDoctor() {
    int opcion;

    do {
        generarTitulos("Administracion", "Mostrar Calendario Por Doctor");

        // Validar que existan especialidades y doctores:
        if (!especialidades->hayEspecialidades() || !doctores->hayDoctores()) {
            cout << "Error: Asegurese de ingresar especialidades y doctores. Digite 0 para salir." << endl;
            opcion = obtenerOpcion(0, 0);
            break;
        }

        // Pedir ID del doctor:
        string id = obtenerEntrada("Digite el ID del doctor: ");

        // Validar existencia del doctor:
        if (!doctores->existeDoctorPorID(id)) {
            cout << "Error: El doctor no ha sido ingresado. Digite 0 para salir." << endl;
            opcion = obtenerOpcion(0, 0);
            break;
        }

        // Se obtiene el doctor:
        doctor* doctorObtenido = doctores->getDoctorPorID(id);

        cout << doctorObtenido->toString();
        cout << doctorObtenido->toStringAgendaCitas();

        cout << "Digite 1 para mostrar la agenda de otro doctor, o digite 0 para salir." << endl;
        opcion = obtenerOpcion(0, 1);
        limpiarPantallaPortable();

    } while (opcion != 0);
}

void baseDeDatos::mostrarCitasPorDueno() {
    int opcion;

    do {
        generarTitulos("Administracion", "Mostrar Citas Por Dueno");

        // Validar que existan duenos y mascotas:
        if (!duenos->hayDuenos() || !mascotas->hayMascotas()) {
            cout << "Error: Asegurese de ingresar duenos y mascotas. Digite 0 para salir." << endl;
            opcion = obtenerOpcion(0, 0);
            break;
        }

        // Pedir ID del dueno:
        string id = obtenerEntrada("Digite el ID del dueno: ");

        // Validar existencia del dueno:
        if (!duenos->existeDuenoPorID(id)) {
            cout << "Error: El dueno no ha sido ingresado. Digite 0 para salir." << endl;
            opcion = obtenerOpcion(0, 0);
            break;
        }

        // Se obtiene el dueno:
        dueno* duenoObtenido = duenos->getDuenoPorID(id);

        // Validar que hayan mascotas con apuntando a ese dueno obtenido:
        if (!mascotas->duenoTieneMascotas(duenoObtenido)) {
            cout << "Error: El dueno no tiene mascotas. Digite 0 para salir." << endl;
            opcion = obtenerOpcion(0, 0);
            break;
        }

        // Validar que el dueno tenga mascotas con citas registradas:
        if (!mascotas->elDuenoTieneMascotasConCitasRegistradas(duenoObtenido)) {
            cout << "Error: Las mascotas del dueno no tienen citas registradas. Digite 0 para salir." << endl;
            opcion = obtenerOpcion(0, 0);
            break;
        }

        // Filtrar las citas correpondientes al dueno:
        cout << doctores->mostrarTodasLasCitasDelDueno(duenoObtenido);

        cout << "Digite 1 para mostrar las citas de otro dueno, o digite 0 para salir." << endl;
        opcion = obtenerOpcion(0, 1);
        limpiarPantallaPortable();

    } while (opcion != 0);
}

void baseDeDatos::mostrarListadoDeEspecialidades() {
    int opcion;

    do {
        generarTitulos("Busquedas y Listados", "Mostrar Especialidades");

        // Validar que existan especialidades:
        if (!especialidades->hayEspecialidades()) {
            cout << "Error: Asegurese de ingresar especialidades. Digite 0 para salir." << endl;
            opcion = obtenerOpcion(0, 0);
            break;
        }

        cout << especialidades->toString() << endl;

        cout << "Digite 0 para salir." << endl;
        opcion = obtenerOpcion(0, 1);
        limpiarPantallaPortable();

    } while (opcion != 0);
}

void baseDeDatos::mostrarListadoDeDoctoresPorEspecialidad() {
    int opcion;

    do {
        generarTitulos("Busquedas y Listados", "Mostrar Doctores por Especialidad");

        // Validar que existan especialidades:
        if (!especialidades->hayEspecialidades() || !doctores->hayDoctores()) {
            cout << "Error: Asegurese de ingresar especialidades y doctores. Digite 0 para salir." << endl;
            opcion = obtenerOpcion(0, 0);
            break;
        }

        // Mostrar las especialidades registradas:
        cout << especialidades->toString();

        // Solicitar una especialidad de las mostradas:
        string codEsp = obtenerEntrada("Ingrese el codigo de la especialidad: ");

        // Validar especialidad existente:
        if (!especialidades->existeEspecialidadPorCodigo(codEsp)) {
            cout << "Error: La especialidad ingresada no existe. Digite 0 para salir." << endl;
            opcion = obtenerOpcion(0, 0);
            break;
        }

        // Obtener especialidad:
        especialidad* espObtenida = especialidades->getEspPorCodigo(codEsp);

        // Validar que al menos un doctor apunte a esa especialidad:
        if (!doctores->especialidadTieneDoctores(espObtenida)) {
            cout << "Error: La especialidad no tiene doctores. Digite 0 para salir." << endl;
            opcion = obtenerOpcion(0, 0);
            break;
        }

        // Motrar los doctores que apuntan a esa especialidad:
        cout << doctores->toStringDoctoresPorEspecialidad(espObtenida);

        cout << "Digite 0 para salir." << endl;
        opcion = obtenerOpcion(0, 1);
        limpiarPantallaPortable();

    } while (opcion != 0);
}

void baseDeDatos::mostrarDuenosConSusMascotas() {
    int opcion;

    do {
        generarTitulos("Busquedas y Listados", "Mostrar Mascotas y sus Duenos");

        // Validar que existan duenos y mascotas:
        if (!duenos->hayDuenos() || !mascotas->hayMascotas()) {
            cout << "Error: Asegurese de ingresar duenos y mascotas. Digite 0 para salir." << endl;
            opcion = obtenerOpcion(0, 0);
            break;
        }

        // Mostrar las mascotas registradas y sus duenos:
        cout << mascotas->toString();

        cout << "Digite 0 para salir." << endl;
        opcion = obtenerOpcion(0, 1);
        limpiarPantallaPortable();

    } while (opcion != 0);
}

void baseDeDatos::mostrarPacientesPorDoctor() {
    int opcion;

    do {
        generarTitulos("Busquedas y Listados", "Mostrar Pacientes por doctor");

        // Validar que existan especialidades, doctores, duenos y mascotas:
        if (!doctores->hayDoctores() || !mascotas->hayMascotas()) {
            cout << "Error: Asegurese de ingresar doctores y mascotas. Digite 0 para salir." << endl;
            opcion = obtenerOpcion(0, 0);
            break;
        }

        // Pedir ID del doctor:
        string id = obtenerEntrada("Digite el ID del doctor: ");

        // Validar existencia del doctor:
        if (!doctores->existeDoctorPorID(id)) {
            cout << "Error: El doctor no ha sido ingresado. Digite 0 para salir." << endl;
            opcion = obtenerOpcion(0, 0);
            break;
        }

        // Se obtiene el doctor:
        doctor* doctorObtenido = doctores->getDoctorPorID(id);

        // Validar que el doctor tenga citas registradas:
        if (!doctorObtenido->tieneCitas()) {
            cout << "Error: El doctor no tiene citas registradas. Digite 0 para salir." << endl;
            opcion = obtenerOpcion(0, 0);
            break;
        }

        // Mostras las citas del doctor:
        cout << doctorObtenido->toStringPacientesDelDoctor();

        cout << "Digite 0 para salir." << endl;
        opcion = obtenerOpcion(0, 1);
        limpiarPantallaPortable();

    } while (opcion != 0);
}

// ------------------------------------------------------------------------- //

// Faltaría Persistencia de Datos en las Citas registradas en el sistema:

// Persistencia de Datos:
void baseDeDatos::guardarEspecialidades() {
    int opcion;

    do {
        generarTitulos("Submenu Persistencia De Datos", "Guardar Especialidades");

        // Validar existencia de especialidades antes de guardar:
        if (especialidades->getCan() == 0) {
            cout << "Error: No hay especialidades ingresadas. Digite 0 para salir." << endl;
            opcion = obtenerOpcion(0, 0);
            break;
        }

        // Validar si se guardaron correctamente los datos:
        if (especialidades->guardarDatos()) {
            cout << "Datos guardados correctamente. Digite 0 para salir." << endl;
        }
        else {
            cout << "Error: No se pudo leer el archivo. Digite 0 para salir." << endl;
        }

        opcion = obtenerOpcion(0, 0);
        limpiarPantallaPortable();

    } while (opcion != 0);
}

void baseDeDatos::cargarEspecialidades() {
    int opcion;

    do {
        generarTitulos("Submenu Persistencia De Datos", "Cargar Especialidades");

        // Validar si se cargaron los datos correctamente:
        if (especialidades->cargarDatos()) {
            // Mostrar los datos cargados:
            cout << especialidades->toString() << endl;
            cout << "Datos cargados correctamente. Digite 0 para salir." << endl;
        }
        else {
            cout << "Error: No se pudo leer el archivo. Digite 0 para salir." << endl;
        }

        opcion = obtenerOpcion(0, 0);
        limpiarPantallaPortable();

    } while (opcion != 0);
}

void baseDeDatos::guardarDoctores() {
    int opcion;

    do {
        generarTitulos("Submenu Persistencia De Datos", "Guardar Doctores");

        // Si no hay especialidades, no hay doctores:
        if (especialidades->getCan() == 0) {
            cout << "Error: No hay especialidades ingresadas. Digite 0 para salir." << endl;
            opcion = obtenerOpcion(0, 0);
            break;
        }

        // Validar la existencia de doctores:
        if (doctores->getCan() == 0) {
            cout << "Error: No hay doctores ingresados. Digite 0 para salir." << endl;
            opcion = obtenerOpcion(0, 0);
            break;
        }

        // Validar que se guardaron correctamente los archivos:
        if (doctores->guardarDatos()) {
            cout << "Datos guardados correctamente. Digite 0 para salir." << endl;
        }
        else {
            cout << "Error: No se pudo leer el archivo. Digite 0 para salir." << endl;
        }

        opcion = obtenerOpcion(0, 0);
        limpiarPantallaPortable();

    } while (opcion != 0);
}

void baseDeDatos::cargarDoctores() {
    int opcion;

    do {
        generarTitulos("Submenu Persistencia De Datos", "Cargar Doctores");

        // Deben existir especialidades para generar doctores:
        if (especialidades->getCan() == 0) {
            cout << "Error: No hay especialidades ingresadas. Digite 0 para salir." << endl;
            opcion = obtenerOpcion(0, 0);
            break;
        }

        // Validar la carga de datos:
        if (doctores->cargarDatos(especialidades)) {
            cout << doctores->toString();
            cout << "Datos cargados correctamente. Digite 0 para salir." << endl;
        }
        else {
            cout << "Error: No se pudo leer el archivo. Digite 0 para salir." << endl;
        }

        opcion = obtenerOpcion(0, 0);
        limpiarPantallaPortable();

    } while (opcion != 0);
}

void baseDeDatos::guardarDuenos() {
    int opcion;

    do {
        generarTitulos("Submenu Persistencia De Datos", "Guardar Duenos");

        // Validar existencia de duenos antes de guardar:
        if (duenos->getCan() == 0) {
            cout << "Error: No hay duenos ingresados. Digite 0 para salir." << endl;
            opcion = obtenerOpcion(0, 0);
            break;
        }

        // Validar si se guardaron correctamente los datos:
        if (duenos->guardarDatos()) {
            cout << "Datos guardados correctamente. Digite 0 para salir." << endl;
        }
        else {
            cout << "Error: No se pudo leer el archivo. Digite 0 para salir." << endl;
        }

        opcion = obtenerOpcion(0, 0);
        limpiarPantallaPortable();

    } while (opcion != 0);
}

void baseDeDatos::cargarDuenos() {
    int opcion;

    do {
        generarTitulos("Submenu Persistencia De Datos", "Cargar Duenos");

        // Validar si se cargaron los datos correctamente:
        if (duenos->cargarDatos()) {
            cout << duenos->toString() << endl;
            cout << "Datos cargados correctamente. Digite 0 para salir." << endl;
        }
        else {
            cout << "Error: No se pudo leer el archivo. Digite 0 para salir." << endl;
        }

        opcion = obtenerOpcion(0, 0);
        limpiarPantallaPortable();

    } while (opcion != 0);
}

void baseDeDatos::guardarMascotas() {
    int opcion;

    do {
        generarTitulos("Submenu Persistencia De Datos", "Guardar Mascotas");

        // Si no hay duenos, no hay doctores:
        if (duenos->getCan() == 0) {
            cout << "Error: No hay duenos ingresados. Digite 0 para salir." << endl;
            opcion = obtenerOpcion(0, 0);
            break;
        }

        // Validar la existencia de mascotas:
        if (mascotas->getCan() == 0) {
            cout << "Error: No hay mascotas ingresadas. Digite 0 para salir." << endl;
            opcion = obtenerOpcion(0, 0);
            break;
        }

        // Validar que se guardaron correctamente los archivos:
        if (mascotas->guardarDatos()) {
            cout << "Datos guardados correctamente. Digite 0 para salir." << endl;
        }
        else {
            cout << "Error: No se pudo leer el archivo. Digite 0 para salir." << endl;
        }

        opcion = obtenerOpcion(0, 0);
        limpiarPantallaPortable();

    } while (opcion != 0);
}

void baseDeDatos::cargarMascotas() {
    int opcion;

    do {
        generarTitulos("Submenu Persistencia De Datos", "Cargar Mascotas");

        // Deben existir duenos para generar mascotas:
        if (duenos->getCan() == 0) {
            cout << "Error: No hay duenos ingresados. Digite 0 para salir." << endl;
            opcion = obtenerOpcion(0, 0);
            break;
        }

        // Validar la carga de datos:
        if (mascotas->cargarDatos(duenos)) {
            cout << mascotas->toString();
            cout << "Datos cargados correctamente. Digite 0 para salir." << endl;
        }
        else {
            cout << "Error: No se pudo leer el archivo. Digite 0 para salir." << endl;
        }

        opcion = obtenerOpcion(0, 0);
        limpiarPantallaPortable();

    } while (opcion != 0);
}

void baseDeDatos::guardadoRapidoDeDatos() {
    especialidades->guardarDatos();
    doctores->guardarDatos();
    duenos->guardarDatos();
    mascotas->guardarDatos();
}

void baseDeDatos::cargadoRapidoDeDatos() {
    especialidades->cargarDatos();
    doctores->cargarDatos(especialidades);
    duenos->cargarDatos();
    mascotas->cargarDatos(duenos);
}