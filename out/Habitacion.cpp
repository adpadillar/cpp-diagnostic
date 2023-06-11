#include "Habitacion.h"

using namespace std;

int Habitacion::get_numero() {
    return numero;
}

bool Habitacion::get_disponible() {
    return disponible;
}

bool Habitacion::checkout() {
    if (!disponible) {
        nombre = "";
        adultos = 0;
        infantes = 0;
        credito = 0;
        cargo = 0;

        disponible = true;

        return true;
    }

    return false;
}

bool Habitacion::realizarCargo(double charge) {
    if (charge > 0) {
        double new_credit = credito - cargo - charge;

        if (new_credit > 0) {
            cargo += charge;
            return true;
        }

        return false;
    }

    return false;
}
