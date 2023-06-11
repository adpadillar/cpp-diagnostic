#ifndef HABITACION_JUNIOR_H
#define HABITACION_JUNIOR_H

#include "Habitacion.h"
#include <string>

class HabitacionJunior: public Habitacion {
    public:
        HabitacionJunior();
        HabitacionJunior(int n);

        bool checkin(std::string guest_name, int adult_count, int child_count, double credit);
        int getTarifaBase();
        std::string toString();
};

#endif
