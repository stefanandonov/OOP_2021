//
// Created by Stefan Andonov on 5/5/21.
//

#include<iostream>
using namespace std;

class Exception {
public:
    virtual void message() {}
};

class ArithmeticException: public Exception {
public:
    void message() override{
        cout<<"Division with 0 is not allowed!"<<endl;
    }
};

class Product {
private:
    int a;
    static int multiplier;
    int divisor = 2;
public:
    Product(int a, int c) : a(a), divisor(c) {
        if (c==0){
            throw ArithmeticException();
        }
        multiplier=10;
    }

    static void setB(int b) {
        Product::multiplier = b;
    }

    void print () {
        cout<<a*multiplier/divisor<<endl;
    }
};

int Product::multiplier = 10;

//inicijalizacija na staticki clen vo klasata

int main () {
    try {
        Product a(10, 0);
        a.print(); //100
//        Product::setB(15); //b -> 15 za site objekti od klasata
        a.print(); //150
//        b.print(); //75
    }
    catch (ArithmeticException & e) {
        e.message();
    }

    try {
        Product b(5, 3);
        b.print(); //50
    }
    catch (ArithmeticException & e) {
        e.message();
    }
    return 0;
}