//
// Created by Stefan Andonov on 5/5/21.
//

/* Adapter design pattern
 * Да се дефинира класа RoundHole во која што ќе се чуваат информации за радиусот на дупката.
 * За класата да се обезбедат соодветните конструктори, get и set методи за радиусот како и еден метод
 * bool fits (RoundPeg * roundPeg)
 * што враќа true/false дали даденa кружна играчкa може да се вклопи во дупката.

Да се дефинира класи за две играчки:

- кружна играчка (RoundPeg). Во класата се чува информација за радиусот на играчката.
 Да се имплементира конструктор и get/sет метод за радиусот.
- квадратна играчка (SqaurePeg). Во класата се чува информацијата за должината на страната на играчката во
 форма на коцка или квадар (не е важна висината). Да се имплементира конструктор и set/get метод за должината
 на страната.

1) Да се имплементира класа што ќе овозможи квадратна коцка да се адаптира како кружна играчка.
2) Да се прикажи како би можело ова да биде исто со дијамант проблемот.
 * */

#include<iostream>
#include<math.h>
using namespace std;

class RoundPeg {
protected:
    double radius;
public:
    RoundPeg(double radius) : radius(radius) {}

    double getRadius() const {
        return radius;
    }

    void setRadius(double radius) {
        RoundPeg::radius = radius;
    }
};

class SquarePeg {
protected:
    double a;
public:
    SquarePeg(double a) : a(a) {}

    double getA() const {
        return a;
    }

    void setA(double a) {
        SquarePeg::a = a;
    }
};

class SquarePegAdapter: public SquarePeg, public RoundPeg {
public:
    SquarePegAdapter(int a = 1): RoundPeg(a*sqrt(2)/2), SquarePeg(a) {

    }
};

class RoundHole {
    int radius;
public:
    RoundHole(int radius) : radius(radius) {}

    int getRadius() const {
        return radius;
    }

    void setRadius(int radius) {
        this->radius = radius;
    }

    bool fits (RoundPeg * roundPeg) {
        return roundPeg->getRadius() <= this->radius;
    }

};

int main () {
    RoundHole roundHole (10);
    RoundPeg * roundPeg = new RoundPeg(11);
    RoundPeg * adapter = new SquarePegAdapter(20);
    cout<<roundHole.fits(roundPeg)<<endl;
    cout<<roundHole.fits(adapter)<<endl;
    return 0;
}