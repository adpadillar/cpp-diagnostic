#include <iostream>

#include "../include/hotel.h"
#include "../include/HabitacionDeluxe.h"
#include "../include/HabitacionJunior.h"
#include "../include/HabitacionSuite.h"

using namespace std;

Hotel::Hotel(string name, int n_junior, int n_suite, int n_deluxe) {
    this->size = n_junior + n_suite + n_deluxe;
    this->nombre = name;
    this->n_junior = n_junior;
    this->n_suite = n_suite;
    this->n_deluxe = n_deluxe;

    int n = 0;
    for (int i = 0; i < n_junior; i++, n++) {
        habitaciones.push_back(new HabitacionJunior(n + 100));
    }
    for (int i = 0; i < n_suite; i++, n++) {
        habitaciones.push_back(new HabitacionSuite(n + 100));
    }
    for (int i = 0; i < n_deluxe; i++, n++) {
        habitaciones.push_back(new HabitacionDeluxe(n + 100));
    }
};

int Hotel::checkin(string guest_name, int adult_count, int child_count, double credit, int room_type) {
    if (room_type == 1) {
        // Habitacion Junior
        for (int i = 0; i < n_junior; i++) {
            Habitacion* r = habitaciones[i];

            if (r->get_disponible()) {
                r->checkin(guest_name, adult_count, child_count, credit);
                return r->get_numero();
            }
        }
    }

    if (room_type == 2) {
        // Habitacion Suite
        for (int i = n_junior; i < n_junior + n_suite; i++) {
            Habitacion* r = habitaciones[i];

            if (r->get_disponible()) {
                r->checkin(guest_name, adult_count, child_count, credit);
                return r->get_numero();
            }
        }
    }

    if (room_type == 4) {
        // Habitacion Deluxe
        for (int i  = n_junior + n_suite; i < n_junior + n_suite + n_deluxe; i++) {
            cout << i << endl;
            Habitacion* r = habitaciones[i];

            if (r->get_disponible()) {
                r->checkin(guest_name, adult_count, child_count, credit);
                return r->get_numero();
            }
        }
    }

    return -1;
}

bool Hotel::checkout(int number) {
    for (int i = 0; i < size; i++) {
        Habitacion* r = habitaciones[i];

        if (r->get_numero() == number) {
            return r->checkout();
        }
    }

    return false;
}

bool Hotel::realizarCargosHabitacion(int number, double charge) {
    for (int i = 0; i < size; i++) {
        Habitacion* r = habitaciones[i];

        if (r->get_numero() == number && !r->get_disponible()) {
            return r->realizarCargo(charge);
        }
    }

    return false;
}

int Hotel::getTotalXTarifaBase() {
    int total = 0;

    for (int i = 0; i < size; i++) {
        Habitacion* r = habitaciones[i];

        total += r->getTarifaBase();
    }

    return total;
}

void Hotel::imprimeOcupacion() {
    cout << "Ocupacion en el Hotel " << nombre << endl;
    int busy_count = 0;

    for (int i = 0; i < size; i++) {
        if (!habitaciones[i]->get_disponible()) {
            cout << habitaciones[i]->toString() << endl;
            busy_count++;
        }
    }

    if (busy_count == 0) {
        cout << "No hay habitaciones ocupadas" << endl;
    }
}
