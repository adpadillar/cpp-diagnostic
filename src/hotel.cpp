#include "../include/hotel.h"

#include <iostream>

using namespace std;

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
    int busy_count = 0;

    for (int i = 0; i < size; i++) {
        if (!habitaciones[i].get_disponible()) {
            cout << habitaciones[i].toString() << endl;
            busy_count++;
        }
    }

    if (busy_count == 0) {
        cout << "No hay habitaciones ocupadas" << endl;
    }
}
