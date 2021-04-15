//
// Created by Stefan Andonov on 4/15/21.
//

#include<iostream>
using namespace std;
class Animal {
protected:
    char name [20];
    int age;
public:
    Animal (char * name = "noname", int age = 0) {
        strcpy(this->name, name);
        this->age = age;
    }

    Animal (const Animal & a) {
        strcpy(this->name, a.name);
        this->age = a.age;
    }

    friend ostream & operator << (ostream &out, const Animal & a) {
        return out<<a.name<<" "<<a.age;
    }

    void sound () {
        cout<<"UNKNOWN SOUND"<<endl;
    }
};

class Dog: public Animal {
    char breed [20];
    int treats;
public:
    Dog (char * name = "noname", int age = 0, char * breed = "nobreed", int treats = 0) : Animal(name, age) {
        strcpy(this->breed, breed);
        this->treats = treats;
    }

    Dog (const Dog & d) : Animal(d){
        strcpy(this->breed, d.breed);
        this->treats = d.treats;
    }

    friend ostream & operator << (ostream &out, const Dog & d) { //jackie 5 pinch 5
        Animal animal (d);
        return out<<"DOG: "<<animal<<" "<<d.breed<<" "<<d.treats<<endl;
    }

    void sound () {
        cout<<"AW AW AW"<<endl;
    }

};
int main () {
    Animal a;
    Dog d ("jackie", 5, "pinch", 5);
    cout<<d;
    a.sound();
    d.sound();

    Animal * ptr = &a;
    cout<<*ptr<<endl;
    ptr = &d;
    cout<<*ptr<<endl;
    return 0;
}