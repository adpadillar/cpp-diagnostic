#ifndef HABITACION_H
#define HABITACION_H

#include <sstream>
#include <string>

class Habitacion {
    protected:
        int numero;
        int infantes;
        bool disponible;
        std::string nombre;
        double credito;
        int adultos;
        double cargo;

    public:
        Habitacion();
        Habitacion(int n);

        int get_numero();
        bool get_disponible();
        bool checkout();
        bool realizarCargo(double charge);

        virtual bool checkin(std::string guest_name, int adult_count, int child_count, double credit) = 0;
        virtual int getTarifaBase() = 0;
        virtual std::string toString() = 0;
};

#endif
