#include <iostream>

using namespace std;


int mcd(int n1, int n2) {
    int a, b, res;

    a = max(n1, n2);
    b = min(n1, n2);

    do {
        res = b;
        b = a % b;
        a = res;
    } while (b != 0);

    return res;
}


class Fraccion {
    private:
        int num = 0;
        int den = 1;
        
        Fraccion reduce() {
            int n = mcd(this->num, this->den);
            while (n != 1) {
                this->num /= n;
                this->den /= n;

                n = mcd(this->num, this->den);
            }

            return *this;
        }

        Fraccion mult(Fraccion f) {
            Fraccion res(this->num * f.get_num(), this->den * f.get_den(), false);
            return res;
        }

    public:
        Fraccion(int n, int d) {
            this->num = n;
            this->den = d;

            this->reduce();
        };

        Fraccion(int n, int d, bool r) {
            this->num = n;
            this->den = d;

            if (r) {
                this->reduce();
            } 
        }

        int get_num() {
            return this->num;
        }

        int get_den() {
            return this->den;
        }

        Fraccion operator+(Fraccion f) {
            Fraccion c1(f.get_den(), f.get_den(), false); // 1
            Fraccion c2(this->get_den(), this->get_den(), false); // 1

            Fraccion d1 = this->mult(c1);
            Fraccion d2 = f.mult(c2);

            Fraccion res(d1.get_num() + d2.get_num(), d1.get_den());
       
            return res;
        }

        Fraccion operator*(Fraccion f) {
            Fraccion res(this->num * f.get_num(), this->den * f.get_den());

            return res;
        }

        void print() {
            cout << this->num << "/" << this->den << endl;
        }
};

int main() {
    Fraccion f1(1, 13);
    Fraccion f2(1, 24);

    Fraccion f3 = f1 + f2;

    f3.print();

    return 0;
};

