#include "HabitacionSuite.h"

#include <string>

using namespace std;

HabitacionSuite::HabitacionSuite() {
    nombre = "";
    numero = 0;
    adultos = 0;
    infantes = 0;
    credito = 0;
    cargo = 0;
    disponible = true;
};

HabitacionSuite::HabitacionSuite(int n) {
    nombre = "";
    numero = n;
    adultos = 0;
    infantes = 0;
    credito = 0;
    cargo = 0;
    disponible = true;
};

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

