#include <iostream>
#include <sstream>
#include <vector>

#include "../include/hotel.h"

using namespace std;

int main() {
    vector<Hotel> hoteles;

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
                        cout << "Ingresa el nombre del hotel: ";
                        cin >> name;

                        // hoteles.push_back();
                        break;
                    }

            case 2: {
                        // Check in
                        break;
                    }

            case 3: {
                        // Check out
                        break;
                    }

            case 4: {
                        // Realizar cargos
                        break;
                    }

            case 5: {
                        // Total tarifa base
                        break;
                    }

            case 6: {
                        // Total tarifa base
                        break;
                    }

            case 7: { break; }
        }

    } while (opc != 7);

    return 0;
};
