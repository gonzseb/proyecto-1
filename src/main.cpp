#include "sistema.h"

int main() {
    sistema* citasVet = new sistema();

    citasVet->mostrarMenuPrincipal();

    delete citasVet;

    return 0;
}