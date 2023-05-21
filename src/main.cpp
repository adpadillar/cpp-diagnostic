#include <iostream>
#include <sstream>
#include <vector>

#include "../include/hotel.h"

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
