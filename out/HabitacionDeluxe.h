#ifndef HABITACION_DELUXE_H
#define HABITACION_DELUXE_H

#include "Habitacion.h"
#include <string>

class HabitacionDeluxe: public Habitacion {
    public:
        HabitacionDeluxe();
        HabitacionDeluxe(int n);

        bool checkin(std::string guest_name, int adult_count, int child_count, double credit);
        int getTarifaBase();
        std::string toString();
};

#endif // !HABITACION_DELUXE_H
