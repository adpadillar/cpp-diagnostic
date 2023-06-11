#ifndef HOTEL_H
#define HOTEL_H

#include <string>
#include <vector>

#include "habitacion.h"

class Hotel {
    private:
        std::vector<Habitacion*> habitaciones;
        int size;
        std::string nombre;
        int n_junior, n_suite, n_deluxe;

    public:
        Hotel(std::string name, int n_junior, int n_suite, int n_deluxe);

        int checkin(std::string guest_name, int adult_count, int child_count, double credit, int room_type);
        bool checkout(int number);
        bool realizarCargosHabitacion(int number, double charge);
        int getTotalXTarifaBase();
        void imprimeOcupacion();
};

#endif
