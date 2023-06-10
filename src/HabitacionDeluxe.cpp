#include "../include/HabitacionDeluxe.h"
#include "../include/habitacion.h"

#include <string>

using namespace std;

HabitacionDeluxe::HabitacionDeluxe(): Habitacion() {};

HabitacionDeluxe::HabitacionDeluxe(int n): Habitacion(n) {};

bool HabitacionDeluxe::checkin(string guest_name, int adult_count, int child_count,double credit) {
    if ((adult_count + child_count) <= 8) {
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

int HabitacionDeluxe::getTarifaBase() {
    return (adultos * 450) + (infantes * 150) * 1.50;
};


string HabitacionDeluxe::toString() {
    ostringstream ss;

    ss << numero << ",Huesped:" << nombre << ",Tarifa Base:" << getTarifaBase() << ",Credito:" << credito << ",Cargos:" << cargo << ",Habitacion Deluxe";

    return ss.str();
}
