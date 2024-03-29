#include "habitacion.h"

using namespace std;

Habitacion::Habitacion() {
    nombre = "";
    numero = 0;
    adultos = 0;
    infantes = 0;
    credito = 0;
    cargo = 0;
    disponible = true;
}

Habitacion::Habitacion(int n) {
    nombre = "";
    numero = n;
    adultos = 0;
    infantes = 0;
    credito = 0;
    cargo = 0;
    disponible = true;
}

int Habitacion::get_numero() {
    return numero;
}

bool Habitacion::get_disponible() {
    return disponible;
}

Habitacion Habitacion::checkin(string guest_name, int adult_count, int child_count, double credit) {
    this->nombre = guest_name;
    this->adultos = adult_count;
    this->infantes = child_count;
    this->credito = credit;
    this->cargo = 0;

    this->disponible = false;

    return *this;
}

int Habitacion::getTarifaBase() {
    return (adultos * 450) + (infantes * 150);
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

string Habitacion::toString() {
    ostringstream ss;

    ss << numero << ",Huesped:" << nombre << ",Tarifa Base:" << getTarifaBase() << ",Credito:" << credito << ",Cargos:" << cargo;

    return ss.str();
}
