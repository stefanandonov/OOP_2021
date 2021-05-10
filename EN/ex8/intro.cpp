//
// Created by Stefan Andonov on 4/15/21.
//

#include<iostream>
using namespace std;
class Animal {
protected:
    char name [20];
    int age;
    char breed [20];
public:
    Animal (char * name = "noname", int age = 0, char * breed = "") {
        strcpy(this->name, name);
        this->age = age;
        strcpy(this->breed, breed);
    }

    Animal (const Animal & a) {
        strcpy(this->name, a.name);
        this->age = a.age;
    }

    virtual void print () = 0; //=0 --> method to pure virtual

    virtual void sound () = 0;
};

class Dog: public Animal {
    int treats;
public:
    Dog (char * name = "noname", int age = 0, char * breed = "nobreed", int treats = 0) : Animal(name, age, breed) {
        this->treats = treats;
    }

    Dog (const Dog & d) : Animal(d){
        this->treats = d.treats;
    }

    void print() override { //jackie 5 pinch 5
        cout<<"DOG: "<<name<<" "<<age<<" "<<breed<<" "<<treats<<endl;
    }

    void sound () override {
        cout<<"AW AW AW"<<endl;
    }
};

class Cat : public Animal{
    char color [10];
public:
    Cat (char * name = "noname", int age = 0, char * breed = "nobreed",char * color = "") : Animal(name, age, breed){
        strcpy(this->color, color);
    }

    Cat (const Cat & d) : Animal(d){
        strcpy(this->color, d.color);
    }

    void print() override {
        cout<<"CAT: "<<name<<" "<<age<<" "<<breed<<" "<<color<<endl;
    }

    void sound() override {
        cout<<"MJAU MJAU MJAU"<<endl;
    }


};

class Zoo {
    Animal ** animals; //array of pointers
public:
    Zoo() {
        animals = new Animal * [0];
    }

    ~Zoo() {
        delete [] animals;
    }

};
int main () {

    Dog d ("jackie", 5, "pinch", 5);
//    cout<<d;
//    a.sound();
//    d.sound();

    Animal * a1 = new Dog("jackie", 5, "pinch", 5);
    a1->print();
    a1->sound();
    Animal * a2 = new Cat("tom", 4, "siamese", "gray");
    a2->print();
    a2->sound();

    Animal ** animals = new Animal * [2];
    animals[0] = a1;
    animals[1] = a2;

    for (int i=0;i<2;i++)
        animals[i]->print();

    return 0;
}