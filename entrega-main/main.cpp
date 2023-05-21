#include <iostream>
#include <sstream>
#include <vector>

#include "hotel.h"

using namespace std;

int main() {
    Hotel h("Holiday Inn");

    int opc;
    do {
        cout << "0. Salir" << endl;
        cout << "1. Check in" << endl;
        cout << "2. Check out" << endl;
        cout << "3. Realizar cargos" << endl;
        cout << "4. Total tarifa base" << endl;
        cout << "5. Imprime ocupacion" << endl;

        cin >> opc;

        switch (opc) {
            case 0: { break; }

            case 1: {
                        string name;
                        int adults;
                        int children;
                        double credit;

                        cout << "Ingresa el nombre del huesped: ";
                        cin >> name;

                        cout << "Ingresa la cantidad de adultos: ";
                        cin >> adults;

                        cout << "Ingresa la cantidad de niños: ";
                        cin >> children;

                        cout << "Ingresa la cantidad de credito: ";
                        cin >> credit;

                        int room_n = h.checkin(name, adults, children, credit);

                        cout <<  "Se asigno la habitacion: " << room_n << endl; 
                        break;
                    }

            case 2: {
                        int room_n;
                        cout << "Ingresa el numero de habitacion: ";
                        cin >> room_n;

                        bool success = h.checkout(room_n);
                        string msg = success ? "Check out realizado" : "No se pudo realizar el Check out";

                        cout << msg << endl;
                        break;
                    }

            case 3: {
                        int room_n;
                        double charge;

                        cout << "Ingresa el numero de habitacion: ";
                        cin >> room_n;

                        cout << "Ingresa el cargo: ";
                        cin >> charge;

                        int success = h.realizarCargosHabitacion(room_n, charge);
                        string msg = success ? "Cargo realizado" : "No se pudo realizar el cargo";  

                        cout << msg << endl;
                        break;
                    }

            case 4: {
                        cout << "Total tarifa base: " << h.getTotalXTarifaBase() << endl;
                        break;
                    }

            case 5: {
                        h.imprimeOcupacion();
                        break;
                    }
        }

    } while (opc != 0);

    return 0;
};
