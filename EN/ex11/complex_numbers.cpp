//
// Created by Stefan Andonov on 5/20/21.
//

#include<iostream>

using namespace std;

template<typename T>
class ComplexNumber {
private:
    T r;
    T i;
public:
    ComplexNumber(T r, T i) {
        this->r = r;
        this->i = i;
    };

    ComplexNumber<T> operator+(ComplexNumber<T> other) {
        return ComplexNumber<T>(this->r + other.r, this->i + other.i);
    }

    friend ostream & operator << (ostream & out, const ComplexNumber<T> & complexNumber) {
        if (complexNumber.i>=0)
            return out<<complexNumber.r<<"+"<<complexNumber.i<<"i";
        else
            return out<<complexNumber.r<<complexNumber.i<<"i";
    }
};

int main() {

    ComplexNumber<int> complexNumber (5,6);
    ComplexNumber<int> cn2 (7,-5);

    ComplexNumber<double> cn3 (-5.6, 7.0);

    cout<<complexNumber<<endl<<cn2<<endl;

    cout<<(complexNumber+cn2)<<endl;

//    cout<<(complexNumber+cn3)<<endl;
    return 0;
}