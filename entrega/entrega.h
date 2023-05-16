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
        Habitacion check_in(std::string guest_name, int adult_count, int child_count, double credit);
        bool check_out();
        int get_tarifa_base();
        bool realizar_cargo(double charge);
        std::string to_string();
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

        int check_in(std::string guest_name, int adult_count, int child_count, double credit);
        bool check_out(int number);
        bool realizar_cargos_habitacion(int number, double charge);
        int get_total_tarifa_base();
        void imprime_ocupacion();
};

#endif  
