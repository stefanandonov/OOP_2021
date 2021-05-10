//
// Created by Stefan Andonov on 3/10/21.
//

#include<iostream>
#include<cmath>
#include <iomanip>

using namespace std;

class TriangleNotValid {
    int a, b, c;
public:
    TriangleNotValid(int a, int b, int c) : a(a), b(b), c(c) {}

    void printMessage() {
        cout << "Triangle with sides: " << a << ", " << b << " and " << c << " is not possible!" << endl;
    }
};

class Triangle {
    int a, b, c;
public:
    Triangle(int _a = 5, int _b = 4, int _c = 3) {
        if ((_a + _b <= _c) || (_a + _c <= _b) || (_b + _c <= _a)) //nevaliden triagolnik
            throw TriangleNotValid(_a, _b, _c);
        cout << "Constructor is called" << endl;
        a = _a;
        b = _b;
        c = _c;
    }

    ~Triangle() {
        cout << "Object is destroyed" << endl;
    }

    int perimeter() {
        return a + b + c;
    }

    float area() {
        float s = float(a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    void print() {
        cout << "Triangle with sides: " << a << ", " << b << ", " << c << endl;
        cout << "Perimeter: " << perimeter() << " Area: " << area() << endl;
    }
};

int main() {
    try {
        Triangle t;
        t.print();
        Triangle t1(6, 6, 6);
        t1.print();
        Triangle t2(15, 9, 12);
        t2.print();
    } catch (TriangleNotValid & t) {
        t.printMessage();
    }
    return 0;
}