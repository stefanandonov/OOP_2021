//
// Created by Stefan Andonov on 5/5/21.
//

#include<iostream>
using namespace std;

class Vehicle {
protected:
   int acceleration;
public:
    Vehicle (int acceleration = 1) {
        cout<<"Vehicle constructor"<<endl;
        this->acceleration = acceleration;
    }

    ~Vehicle() {
        cout<<"Vehicle destructor"<<endl;
    }

    virtual void accelerate () {
        cout<<"Vehicle acceleration from "<<acceleration<<" to "<<acceleration+1<<endl;
        acceleration+=1;
    }

};

class Car: virtual public Vehicle {
public:
    Car () : Vehicle(2) {
        cout<<"Car constructor"<<endl;
    }

    ~Car() {
        cout<<"Car destructor"<<endl;
    }

    virtual void drive () {
        cout<<"Car is driving"<<endl;
    }

    void accelerate() {
        cout<<"Car acceleration from "<<acceleration<<" to "<<acceleration+3<<endl;
        acceleration+=3;
    }
};

class Jet: virtual public Vehicle {
public:
    Jet () : Vehicle(5) {
        cout<<"Jet constructor"<<endl;
    }

    ~Jet() {
        cout<<"Jet destructor"<<endl;
    }

    virtual void fly () {
        cout<<"Jet if flying"<<endl;
    }

    void accelerate() {
        cout<<"Jet acceleration from "<<acceleration<<" to "<<acceleration+5<<endl;
        acceleration+=5;
    }
};

class JetCar : public Jet, public Car {
public:
    JetCar() {
        cout<<"JetCar constructor"<<endl;
    }

    ~JetCar() {
        cout<<"JetCar destructor"<<endl;
    }

    void accelerate() {
        cout<<"Jet acceleration from "<<acceleration<<" to "<<acceleration+5<<endl;
        acceleration+=5;

    }
};

int main () {
    JetCar * jetCar = new JetCar();
    //1problem = 5 constructor calls instead of 4
    //check //2problem = ambiguity when accessing members from the top class in the diamond
//    jetCar->accelerate();

    return 0;
}