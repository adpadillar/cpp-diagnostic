#include <iostream>
#include <sstream>
#include <vector>

#include "../include/hotel.h"

using namespace std;

int main() {
    Hotel h("Holiday Inn");

    h.check_in("Axel", 2, 3, 450.23);
    h.check_in("Jorge", 2, 3, 450.23);
    h.realizar_cargos_habitacion(101, 100);
    h.realizar_cargos_habitacion(100, 400);

    h.imprime_ocupacion();

    h.check_out(100);

    h.imprime_ocupacion();

    return 0;
};
