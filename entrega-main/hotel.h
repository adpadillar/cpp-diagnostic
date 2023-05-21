#ifndef HOTEL_H
#define HOTEL_H

#include <string>
#include <vector>

#include "habitacion.h"

class Hotel {
   private:
    Habitacion habitaciones[50];
    int size;
    std::string nombre;

   public:
    Hotel(std::string name);

    int checkin(std::string guest_name, int adult_count, int child_count, double credit);
    bool checkout(int number);
    bool realizarCargosHabitacion(int number, double charge);
    int getTotalXTarifaBase();
    void imprimeOcupacion();
};

#endif
