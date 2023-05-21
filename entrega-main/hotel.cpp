#include "hotel.h"

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

int Hotel::check_in(string guest_name, int adult_count, int child_count, double credit) {
    for (int i = 0; i < size; i++) {
        Habitacion& r = habitaciones[i];

        if (r.get_disponible()) {
            r.check_in(guest_name, adult_count, child_count, credit);
            return r.get_numero();
        }
    }

    return -1;
}

bool Hotel::check_out(int number) {
    for (int i = 0; i < size; i++) {
        Habitacion& r = habitaciones[i];

        if (r.get_numero() == number) {
            return r.check_out();
        }
    }

    return false;
}

bool Hotel::realizar_cargos_habitacion(int number, double charge) {
    for (int i = 0; i < size; i++) {
        Habitacion& r = habitaciones[i];

        if (r.get_numero() == number && !r.get_disponible()) {
            return r.realizar_cargo(charge);
        }
    }

    return false;
}

int Hotel::get_total_tarifa_base() {
    int total = 0;

    for (int i = 0; i < size; i++) {
        Habitacion& r = habitaciones[i];

        total += r.get_tarifa_base();
    }

    return total;
}

void Hotel::imprime_ocupacion() {
    cout << "Ocupacion en el Hotel " << nombre << endl;
    int busy_count = 0;

    for (int i = 0; i < size; i++) {
        if (!habitaciones[i].get_disponible()) {
            cout << habitaciones[i].to_string() << endl;
            busy_count++;
        }
    }

    if (busy_count == 0) {
        cout << "No hay habitaciones ocupadas" << endl;
    }
}