//
// Created by Stefan Andonov on 4/29/21.
//

#include<iostream>
using namespace std;

class Vehicle {
protected:
    double acceleration;
public:
    Vehicle (double acceleration = 0.0){
        cout<<"Vehicle constructor called"<<endl;
        this->acceleration = acceleration;
    }

    ~Vehicle() {
        cout<<"Vehicle desutrctor called"<<endl;
    }

    virtual void accelerate () {
        ++acceleration;
        cout<<"Vehicle acceleration increased"<<endl;
    }
};

class Car : virtual public Vehicle {
public:
    Car () : Vehicle(2){
        cout<<"Car constructor called"<<endl;
    }

    ~Car() {
        cout<<"Car destructor called"<<endl;
    }

    void accelerate() override{
        acceleration+=1.5;
        cout<<"Car acceleration increased"<<endl;
    }

    virtual void drive () {
        cout<<"Car is driving"<<endl;
    }
};

class Jet : virtual public Vehicle {
public:
    Jet () : Vehicle (5) {
        cout<<"Jet constructor called"<<endl;
    }

    ~Jet () {
        cout<<"Jet destructor called"<<endl;
    }

    void accelerate() override {
        acceleration+=4;
        cout<<"Jet acceleration increased"<<endl;
    }

    virtual void fly () {
        cout<<"Jet is flying"<<endl;
    }
};

class JetCar : public Jet, public Car {
public:
    JetCar() {
        cout<<"JetCar constructor called"<<endl;
    }

    ~JetCar() {
        cout<<"JetCar destructor called"<<endl;
    }

    void accelerate() override {
        acceleration+=7;
        cout<<"JetCar acceleration increased"<<endl;
    }

    void drive() override {
        cout<<"JetCar is driving"<<endl;
    }

    void fly() override {
        cout<<"JetCar is flying"<<endl;
    }
};

int main () {
//    Car * car = new Car();
//    car->accelerate();
//    car->drive();
//
//    Jet * jet = new Jet();
//    jet->accelerate();
//    jet->fly();

    JetCar * jetCar = new JetCar();
    delete jetCar;
//    jetCar->accelerate();
//    jetCar->drive();
//    jetCar->fly();
    return 0;
}