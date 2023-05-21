#ifndef HABITACION_H
#define HABITACION_H

#include <string>
#include <sstream>

class Habitacion {
    private:
        int numero;
        std::string nombre;
        int adultos;
        int infantes;
        double credito;
        double cargo;
        bool disponible;

    public:
        Habitacion();
        Habitacion(int n);
        int get_numero();
        bool get_disponible();
        Habitacion checkin(std::string guest_name, int adult_count, int child_count, double credit);
        bool checkout();
        int getTarifaBase();
        bool realizarCargo(double charge);
        std::string toString();
};

#endif
