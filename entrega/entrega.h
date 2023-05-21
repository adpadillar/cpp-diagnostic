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
#ifndef HOTEL_H
#define HOTEL_H

#include <vector>
#include <string>

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
