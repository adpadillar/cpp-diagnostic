#include <vector>
#include <iostream>

#include "../include/hotel.h"

using namespace std;

int main() {
    vector<Hotel*> hoteles;

    int opc;
    do {
        cout << "1. Crear Hotel" << endl;
        cout << "2. Check in" << endl;
        cout << "3. Check out" << endl;
        cout << "4. Realizar cargos" << endl;
        cout << "5. Total tarifa base" << endl;
        cout << "6. Imprime ocupacion" << endl;
        cout << "7. Salir" << endl;

        cin >> opc;

        switch (opc) {
            case 1: {
                        // Crear Hotel
                        string name;    
                        int n_junior, n_suite, n_deluxe;

                        cout << "Ingresa el nombre del hotel: ";
                        cin >> name;

                        cout << "Ingresa la cantidad de habitaciones Junior del hotel: ";
                        cin >> n_junior;

                        cout << "Ingresa la cantidad de habitaciones Suite del hotel: ";
                        cin >> n_suite;

                        cout << "Ingresa la cantidad de habitaciones Deluxe del hotel: ";
                        cin >> n_deluxe;

                        hoteles.push_back(new Hotel(name, n_junior, n_suite, n_deluxe));

                        break;
                    }

            case 2: {
                        // Check in
                        if (hoteles.size() > 0) {
                            string name;
                            int adults;
                            int children;
                            double credit;
                            int room_type;
                            Hotel* h = hoteles[0];

                            cout << "Ingresa el nombre del huesped: ";
                            cin >> name;

                            cout << "Ingresa la cantidad de adultos: ";
                            cin >> adults;

                            cout << "Ingresa la cantidad de niños: ";
                            cin >> children;

                            cout << "Ingresa la cantidad de credito: ";
                            cin >> credit;

                            cout << "Ingresa el tipo de habitacion: " << endl;
                            cout << "\t1. Habitacion Junior" << endl;
                            cout << "\t2. Habitacion Suite" << endl;
                            cout << "\t4. Habitacion Deluxe" << endl;
                            cout << "Tu seleccion [1, 2, 4]: ";
                            cin >> room_type;

                            int room_n = h->checkin(name, adults, children, credit, room_type);
                            string msg = room_n != -1 ? "Se asigno la habitación: " + to_string(room_n) : "No se pudo hacer check in";

                            cout <<  msg << endl; 
                        } else {
                            cout << "No hay hoteles registrados" << endl;
                        }
                        break;
                        
                    }

            case 3: {
                        // Check out
                        if (hoteles.size() > 0) {
                            int room_n;
                            Hotel* h = hoteles[0];
                            cout << "Ingresa el numero de habitacion: ";
                            cin >> room_n;

                            bool success = h->checkout(room_n);
                            string msg = success ? "Check out realizado" : "No se pudo realizar el Check out";

                            cout << msg << endl;
                        } else {
                            cout << "No hay hoteles registrados" << endl;
                        }
                        break;
                    }

            case 4: {
                        // Realizar cargos
                        if (hoteles.size() > 0) {
                            Hotel* h = hoteles[0];
                            int room_n;
                            double charge;

                            cout << "Ingresa el numero de habitacion: ";
                            cin >> room_n;

                            cout << "Ingresa el cargo: ";
                            cin >> charge;

                            int success = h->realizarCargosHabitacion(room_n, charge);
                            string msg = success ? "Cargo realizado" : "No se pudo realizar el cargo";  

                            cout << msg << endl;
                        } else {
                            cout << "No hay hoteles registrados" << endl;
                        }
                        break;
                    }

            case 5: {
                        // Total tarifa base
                        if (hoteles.size() > 0) {
                            Hotel* h = hoteles[0];
                            cout << "Total tarifa base: " << h->getTotalXTarifaBase() << endl;
                        } else {
                            cout << "No hay hoteles registrados" << endl;
                        }
                        break;
                    }

            case 6: {
                        // Imprime ocupacion
                        if (hoteles.size() > 0) {
                            hoteles[0]->imprimeOcupacion();
                        } else {
                            cout << "No hay hoteles registrados" << endl;
                        }
                        break;
                    }

            case 7: { break; }
        }

    } while (opc != 7);

    return 0;
};
