#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Habitacion {
    private:
        int numero;
        string nombre;
        int adultos;
        int infantes;
        double credito;
        double cargo;
        bool disponible;

    public:
        Habitacion() {
            nombre = "";
            numero = 0;
            adultos = 0;
            infantes = 0;
            credito = 0;
            cargo = 0;
            disponible = true;
        }

        Habitacion(int n) {
            nombre = "";
            numero = n;
            adultos = 0;
            infantes = 0;
            credito = 0;
            cargo = 0;
            disponible = true;
        }

        int get_numero() {
            return numero;
        }

        bool get_disponible() {
            return disponible;
        }

        Habitacion check_in(string guest_name, int adult_count, int child_count, double credit) {
            this->nombre = guest_name;
            this->adultos = adult_count;
            this->infantes = child_count;
            this->credito = credit;
            this->cargo = 0;

            this->disponible = false;

            return *this;
        }

        bool check_out() {
            if (!disponible) {
                nombre = "";
                adultos = 0;
                infantes = 0;
                credito = 0;
                cargo = 0;
                
                disponible = true;

                return true;
            }

            return false;
        }

        int get_tarifa_base() {
            return (adultos * 450) + (infantes * 150);
        }

        bool realizar_cargo(double charge) {
            if (charge > 0) {
                double new_credit = credito - charge;

                if (new_credit > 0) {
                    credito = new_credit;
                    return true;
                }

                return false;
            } 

            return false;
        }

        string to_string() {
            ostringstream ss;

            ss << numero << ",Huesped:" << nombre << ",Tarifa Base:" << get_tarifa_base() << ",Credito:" << credito << ",Cargos:" << cargo;

            return ss.str();
        }
};

class Hotel {
    private:
        vector<Habitacion> habitaciones;
        string nombre;

    public:
        Hotel(string name, int size) {
            this->nombre = name;
            for (int i = 0; i < size; i++) {
                Habitacion r(i+1); // Start rooms from 1
                habitaciones.push_back(r);
            }
        };

        int check_in(string guest_name, int adult_count, int child_count, double credit) {
            for (int i = 0; i < habitaciones.size(); i++) {
                Habitacion& r = habitaciones[i];

                if (r.get_disponible()) {
                    r.check_in(guest_name, adult_count, child_count, credit);
                    return r.get_numero();
                }
            }

            return -1;
        }


        bool check_out(int number) {
            if ((int) habitaciones.size() - number >= 0 && number > 0) {
                Habitacion& r = habitaciones[number-1];

                return r.check_out();
            }

            return false;
        }



        bool realizar_cargos_habitacion(int number, double charge) {
            if ((int) habitaciones.size() - number >= 0 && number > 0) {
                Habitacion& r = habitaciones[number-1];

                return r.realizar_cargo(charge);
            }

            return false;
        }

        int get_total_tarifa_base() {
            int total = 0;

            for (int i = 0; i < habitaciones.size(); i++) {
                Habitacion& r = habitaciones[i];

                total += r.get_tarifa_base();
            }

            return total;
        }

        void imprime_ocupacion() {
            cout << "Ocupacion en el Hotel " << nombre << endl;
            
            for (int i = 0; i < habitaciones.size(); i++) {
                cout << habitaciones[i].to_string() << endl;
            }
        }

};


int main() {
    Hotel h("Holiday Inn", 10);

    h.check_in("Axel", 2, 3, 450.23);
    h.check_in("Jorge", 2, 3, 450.23);

    h.imprime_ocupacion();

    h.check_out(1);
    
    h.imprime_ocupacion();

    return 0;
};
