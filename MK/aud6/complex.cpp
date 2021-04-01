//
// Created by Stefan Andonov on 3/31/21.
//

#include<iostream>

using namespace std;

class ComplexNumber {
private:
    double real, imaginary;
public:
    ComplexNumber(double real = 0, double imaginary = 0) {
        this->real = real;
        this->imaginary = imaginary;
    }

    friend ostream &operator<<(ostream &out, const ComplexNumber &c) { //2+3i 2-3i
        return out << c.real << (c.imaginary >= 0 ? "+" : "") << c.imaginary << "i" << endl;
    }

    friend istream &operator>>(istream &in, ComplexNumber &c) {
        return in >> c.real >> c.imaginary;
    }

    //c(this)+c1(other);
    ComplexNumber operator+(const ComplexNumber &other) const {
        return ComplexNumber(real + other.real, imaginary + other.imaginary);
    }

    ComplexNumber operator-(const ComplexNumber &other) const {
        return ComplexNumber(real - other.real, imaginary - other.imaginary);
    }

    //c(this)+=c1(other);
    ComplexNumber & operator += (const ComplexNumber & other) {
        this->real+=other.real;
        this->imaginary+=other.imaginary;
        return *this;
    }

    ComplexNumber & operator -= (const ComplexNumber & other) {
        this->real-=other.real;
        this->imaginary-=other.imaginary;
        return *this;
    }

    friend ComplexNumber operator + (int number, ComplexNumber & cn);
};

ComplexNumber operator + (int number, ComplexNumber & cn) {
    return ComplexNumber(number+cn.real, cn.imaginary);
}

int main() {
    ComplexNumber c(5, -5);
    cout << c;
    ComplexNumber c1 = c;
    cout << c1;
    ComplexNumber fromSI;
    cin >> fromSI;
    cout << fromSI;


    cout<<(c+fromSI);
    cout<<(c-fromSI);

    c+=fromSI;
    cout<<c;
    c-=fromSI;
    cout<<c;

    cout<<fromSI+2;  //2 impliciten konstruktor -> ComplexNumber {real = 2, im = 0};
    cout<<2+fromSI; //operator + (int number, ComplexNumber & cn)
    return 0;
}