#include "../include/hotel.h"

#include <iostream>

using namespace std;

Hotel::Hotel(string name, int size) {
    this->nombre = name;
    for (int i = 0; i < size; i++) {
        Habitacion r(i + 1);  // Start rooms from 1
        habitaciones.push_back(r);
    }
};

int Hotel::check_in(string guest_name, int adult_count, int child_count, double credit) {
    for (int i = 0; i < habitaciones.size(); i++) {
        Habitacion& r = habitaciones[i];

        if (r.get_disponible()) {
            r.check_in(guest_name, adult_count, child_count, credit);
            return r.get_numero();
        }
    }

    return -1;
}

bool Hotel::check_out(int number) {
    if ((int)habitaciones.size() - number >= 0 && number > 0) {
        Habitacion& r = habitaciones[number - 1];

        return r.check_out();
    }

    return false;
}

bool Hotel::realizar_cargos_habitacion(int number, double charge) {
    if ((int)habitaciones.size() - number >= 0 && number > 0) {
        Habitacion& r = habitaciones[number - 1];

        return r.realizar_cargo(charge);
    }

    return false;
}

int Hotel::get_total_tarifa_base() {
    int total = 0;

    for (int i = 0; i < habitaciones.size(); i++) {
        Habitacion& r = habitaciones[i];

        total += r.get_tarifa_base();
    }

    return total;
}

void Hotel::imprime_ocupacion() {
    cout << "Ocupacion en el Hotel " << nombre << endl;

    for (int i = 0; i < habitaciones.size(); i++) {
        cout << habitaciones[i].to_string() << endl;
    }
}
