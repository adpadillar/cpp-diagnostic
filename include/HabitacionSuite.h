#ifndef HABITACION_SUITE_H
#define HABITACION_SUITE_H

#include "habitacion.h"

class HabitacionSuite: public Habitacion {
    public: 
        HabitacionSuite();
        HabitacionSuite(int n);

        bool checkin(std::string guest_name, int adult_count, int child_count, double credit);
        int getTarifaBase();
        std::string toString();
};

#endif // !HABITACION_SUITE_H

