#include "../include/HabitacionSuite.h"
#include "../include/habitacion.h"

#include <string>

using namespace std;

HabitacionSuite::HabitacionSuite(): Habitacion() {};

HabitacionSuite::HabitacionSuite(int n): Habitacion(n) {};

bool HabitacionSuite::checkin(string guest_name, int adult_count, int child_count,double credit) {
    if ((adult_count + child_count) <= 6) {
        this->nombre = guest_name;
        this->adultos = adult_count;
        this->infantes = child_count;
        this->credito = credit;
        this->cargo = 0;

        this->disponible = false;
        return true;
    }

    return false;
}

int HabitacionSuite::getTarifaBase() {
    return (adultos * 450) + (infantes * 150) * 1.30;
};


string HabitacionSuite::toString() {
    ostringstream ss;

    ss << numero << ",Huesped:" << nombre << ",Tarifa Base:" << getTarifaBase() << ",Credito:" << credito << ",Cargos:" << cargo << ",Habitacion Suite";

    return ss.str();
}
