#include <iostream>
#include <string>

using namespace std;

static void limpiarPantallaPortable() {
#ifdef _WIN32
    system("CLS");
#else
    system("clear");
#endif
}

static int obtenerOpcion(int min, int max) {
    int opcion;
    cout << "Ingrese una opcion: ";
    while (!(cin >> opcion) || opcion < min || opcion > max) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Opcion no valida. Intente de nuevo: ";
    }
    cin.ignore(1000, '\n');
    return opcion;
}

static string obtenerEntrada(const string& mensajeP) {
    string entrada;
    do {
        cout << mensajeP;
        getline(cin, entrada);
        cout << endl;
        if (entrada.empty()) {
            cout << "Error: Debe ingresar una entrada valida." << endl << endl;
        }
    } while (entrada.empty());
    return entrada;
}