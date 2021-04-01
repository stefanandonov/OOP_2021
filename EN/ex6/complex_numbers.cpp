//
// Created by Stefan Andonov on 3/29/21.
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

//    ComplexNumber(const ComplexNumber & c) {
//        this->real = c.real;
//        this->imaginary = c.imaginary;
//    }
    ComplexNumber operator+(const ComplexNumber &cn) {
        return ComplexNumber(this->real + cn.real, this->imaginary + cn.imaginary);
    }

    ComplexNumber operator-(const ComplexNumber &cn) {
        return ComplexNumber(this->real - cn.real, this->imaginary - cn.imaginary);
    }

    friend ostream &operator<<(ostream &out, const ComplexNumber &cn) {
        return out << cn.real << (cn.imaginary >= 0 ? "+" : "") << cn.imaginary << "i" << endl;
    }

    ComplexNumber &operator+=(const ComplexNumber &cn) {
        this->real += cn.real;
        this->imaginary += cn.imaginary;
        return *this;
    }

    ComplexNumber &operator-=(const ComplexNumber &cn) {
        this->real -= cn.real;
        this->imaginary -= cn.imaginary;
        return *this;
    }

    friend ComplexNumber operator+(int real, const ComplexNumber &cn);


};

ComplexNumber operator+(int real, const ComplexNumber &cn) {
    return ComplexNumber(cn.real + real, cn.imaginary);
}

int main() {
    ComplexNumber c(5, 6);
    ComplexNumber c1(7.5, -6.4);

    cout << c;
    c -= c1;
    cout << c;
//    cout << c + c1;
//    cout << c - c1;

    cout << c + 10; //ComplexNumber tmp (real=10, imaginary = 0) implicit constructor;
    cout << 10 + c;

}