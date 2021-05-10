//
// Created by Stefan Andonov on 4/29/21.
//

#include<iostream>
#include<math.h>
using namespace std;

class RoundPeg {
protected:
    double radius;
public:
    RoundPeg(double radius) : radius(radius) {}

    friend class RoundHole;
};

class SquarePeg {
protected:
    double side;
public:
    SquarePeg(double side) : side(side) {}
};

class RoundHole {
private:
    double radius;
public:
    RoundHole(double radius) : radius(radius) {}

    bool canFit(RoundPeg &roundPeg) {
        return roundPeg.radius <= this->radius;
    }
};

class AdapterForSquarePeg : public SquarePeg, public RoundPeg {
public:
    AdapterForSquarePeg(int side) : SquarePeg(side), RoundPeg(sqrt(2*side*side)/2) {

    }
};




int main() {

    RoundHole * roundHole = new RoundHole(5);
    RoundPeg * roundPeg = new RoundPeg(4);
    RoundPeg * roundPeg1 = new AdapterForSquarePeg(6);
    cout<<roundHole->canFit(*roundPeg)<<endl;
    cout<<roundHole->canFit(*roundPeg1)<<endl;
    return 0;
}