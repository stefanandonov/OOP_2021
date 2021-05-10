//
// Created by Stefan Andonov on 4/21/21.
//

#include<iostream>
using namespace std;

class Square {
protected:
    int a;
public:
    Square(int a = 1) {
        cout<<"S"<<endl;
        this->a = a;
    }

    Square (const Square & s) {
        cout<<"Copy-constructor for Square"<<endl;
        this->a = s.a;
    }

    ~Square() {
        cout<<"~S"<<endl;
    }

    int perimeter () const {
        return 4*a;
    }

    int area () const {
        return a*a;
    }

    friend ostream & operator << (ostream & out, const Square & s) {
        return out<<s.a<<" "<<s.perimeter()<<" "<<s.area()<<endl;
    }
};

class Rectangle : public Square {
    int b;
public:
    Rectangle(int a = 1, int b = 1) : Square(a) {
        cout<<"R"<<endl;
        this->b=b;
    }

    Rectangle (const Rectangle & r) : Square(r){
        cout<<"Copy-constructor for Rectangle"<<endl;
        this->b = r.b;
    }

    ~Rectangle() {
        cout<<"~R"<<endl;
    }

    int perimeter () const {
        return 2*a+2*b;
    }

    int area () const {
        return a*b;
    }

    friend ostream & operator << (ostream & out, const Rectangle & r) {
        return out<<r.a<<" "<<r.b<<" "<<r.perimeter()<<" "<<r.area()<<endl;
    }
};

int main () {
    Rectangle r(2,3);
    cout<<r;
    return 0;
}