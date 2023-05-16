#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Room {
    private:
        int number;
        string guest_name;
        int adult_count;
        int child_count;
        double credit;
        double charges;
        bool available;

    public:
        Room() {
            guest_name = "";
            number = 0;
            adult_count = 0;
            child_count = 0;
            credit = 0;
            charges = 0;
            available = true;
        }

        Room(int n) {
            guest_name = "";
            number = n;
            adult_count = 0;
            child_count = 0;
            credit = 0;
            charges = 0;
            available = true;
        }

        int get_number() {
            return number;
        }

        bool get_available() {
            return available;
        }

        Room check_in(string guest_name, int adult_count, int child_count, double credit) {
            this->guest_name = guest_name;
            this->adult_count = adult_count;
            this->child_count = child_count;
            this->credit = credit;
            this->charges = 0;

            this->available = false;

            return *this;
        }

        bool check_out() {
            if (!available) {
                guest_name = "";
                adult_count = 0;
                child_count = 0;
                credit = 0;
                charges = 0;
                
                available = true;

                return true;
            }

            return false;
        }

        int get_tarifa_base() {
            return (adult_count * 450) + (child_count * 150);
        }

        bool make_charge(double charge) {
            if (charge > 0) {
                double new_credit = credit - charge;

                if (new_credit > 0) {
                    credit = new_credit;
                    return true;
                }

                return false;
            } 

            return false;
        }

        string to_string() {
            ostringstream ss;

            ss << number << ",Huesped:" << guest_name << ",Tarifa Base:" << get_tarifa_base() << ",Credito:" << credit << ",Cargos:" << charges;

            return ss.str();
        }
};

class Hotel {
    private:
        vector<Room> rooms;
        string name;

    public:
        Hotel(string name, int size) {
            this->name = name;
            for (int i = 0; i < size; i++) {
                Room r(i+1); // Start rooms from 1
                rooms.push_back(r);
            }
        };

        int check_in(string guest_name, int adult_count, int child_count, double credit) {
            for (int i = 0; i < rooms.size(); i++) {
                Room& r = rooms[i];

                if (r.get_available()) {
                    r.check_in(guest_name, adult_count, child_count, credit);
                    return r.get_number();
                }
            }

            return -1;
        }


        bool check_out(int number) {
            if ((int) rooms.size() - number >= 0 && number > 0) {
                Room& r = rooms[number-1];

                return r.check_out();
            }

            return false;
        }



        bool make_charge_room(int number, double charge) {
            if ((int) rooms.size() - number >= 0 && number > 0) {
                Room& r = rooms[number-1];

                return r.make_charge(charge);
            }

            return false;
        }

        int get_total_tarifa_base() {
            int total = 0;

            for (int i = 0; i < rooms.size(); i++) {
                Room& r = rooms[i];

                total += r.get_tarifa_base();
            }

            return total;
        }

        void imprime_ocupacion() {
            cout << "Ocupacion en el Hotel " << name << endl;
            
            for (int i = 0; i < rooms.size(); i++) {
                cout << rooms[i].to_string() << endl;
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
