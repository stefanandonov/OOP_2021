//
// Created by Stefan Andonov on 3/25/21.
//
#include<iostream>
using namespace std;

class Team {
private:
    char name [50];
    int year;
    char city [50];
public:
    Team (char * name = "", int year = 1800, char * city = "") {
        strcpy(this->name, name);
        this->year = year;
        strcpy(this->city, city);
    }

    Team (const Team & t) {
        strcpy(this->name, t.name);
        this->year = t.year;
        strcpy(this->city, t.city);
    }

    void print () {
        cout<<name<<" ("<<year<<") "<<" - "<<city<<endl;
    }
};

int main (){
    Team * t = new Team("Barca", 1890, "Barcelona");
    Team * t1 = new Team("Real Madrid", 1899, "Madrid");
    t->print();
    t1->print();

    delete t;
    delete t1;
    return 0;
}