//
// Created by Stefan Andonov on 3/10/21.
//
#include<iostream>
using namespace std;
class Example {
private:
    int a;
    int b;
public:
    Example() {
        cout<<"Default constructor is  called!"<<endl;
        a = 0;
        b = 0;
    }

    Example(int _a, int _b) { //constructor with arguments
        cout<<"Constructor with arguments is called!"<<endl;
        a = _a;
        b = _b;
    }

    ~Example() {
        cout<<"Object is destroyed"<<endl;
    }

    //get methods
    int getA() {
        return a;
    }

    int getB() {
        return b;
    }

    //set methods
    void setA (int _a) {
        a = _a;
    }

    void setB (int _b) {
        b = _b;
    }

    void print () {
        cout<<"Example: "<<a<<" "<<b<<endl;
    }


};

int main() {
    Example e(10,10);
    //e.a; a is a private member
    Example e1 (15,16);
    Example e2;
    Example e3(15,0);

    e.print();
    e1.print();
    e2.print();
    e2.setA(10);
    e2.setB(-5);
    e2.print();
    e3.print();
    return 0;
}