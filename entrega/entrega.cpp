#include <iostream>

#include "./entrega.h"

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



Hotel::Hotel(string name) {
    this->size = 50;
    this->nombre = name;
    for (int i = 0; i < size; i++) {
        Habitacion r(i + 100);  // Start rooms from 100
        habitaciones[i] = r;
    }
};

int Hotel::checkin(string guest_name, int adult_count, int child_count, double credit) {
    for (int i = 0; i < size; i++) {
        Habitacion& r = habitaciones[i];

        if (r.get_disponible()) {
            r.checkin(guest_name, adult_count, child_count, credit);
            return r.get_numero();
        }
    }

    return -1;
}

bool Hotel::checkout(int number) {
    for (int i = 0; i < size; i++) {
        Habitacion& r = habitaciones[i];

        if (r.get_numero() == number) {
            return r.checkout();
        }
    }

    return false;
}

bool Hotel::realizarCargosHabitacion(int number, double charge) {
    for (int i = 0; i < size; i++) {
        Habitacion& r = habitaciones[i];

        if (r.get_numero() == number && !r.get_disponible()) {
            return r.realizarCargo(charge);
        }
    }

    return false;
}

int Hotel::getTotalXTarifaBase() {
    int total = 0;

    for (int i = 0; i < size; i++) {
        Habitacion& r = habitaciones[i];

        total += r.getTarifaBase();
    }

    return total;
}

void Hotel::imprimeOcupacion() {
    cout << "Ocupacion en el Hotel " << nombre << endl;

    for (int i = 0; i < size; i++) {
        if (!habitaciones[i].get_disponible()) {
            cout << habitaciones[i].toString() << endl;
        }
    }
}
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    Hotel h("Holiday Inn");

    h.checkin("Axel", 2, 3, 450.23);
    h.checkin("Jorge", 2, 3, 450.23);
    h.realizarCargosHabitacion(101, 100);
    h.realizarCargosHabitacion(100, 400);

    h.imprimeOcupacion();

    h.checkout(100);

    h.imprimeOcupacion();

    return 0;
};
