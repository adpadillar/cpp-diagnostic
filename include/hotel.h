#ifndef HOTEL_H
#define HOTEL_H

#include <vector>
#include <string>
#include "habitacion.h"

class Hotel {
    private:
        Habitacion habitaciones[50];
        int size;
        std::string nombre;

    public:
        Hotel(std::string name);

        int check_in(std::string guest_name, int adult_count, int child_count, double credit);
        bool check_out(int number);
        bool realizar_cargos_habitacion(int number, double charge);
        int get_total_tarifa_base();
        void imprime_ocupacion();
};

#endif  
