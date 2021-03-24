//
// Created by Stefan Andonov on 3/24/21.
//


#include<iostream>
#include<cstring>
using namespace std;

class Team {
    char name[50];
    int year;
    char city[50];
public:
    Team(char *_name = "", int _year = 1990, char *_city = "") {
        strcpy(name, _name);
        strcpy(city, _city);
        year = _year;
    }

    Team(const Team &t) {
        cout << "Team copy constructor called" << endl;
        strcpy(name, t.name);
        strcpy(city, t.city);
        year = t.year;
    }

    void print() {
        cout << name << " (" << city << ") " << year << endl;
    }

    char * getName () {
        return name;
    }

};

int main () {
    Team * t1 = new Team("Barca", 1890, "Barcelona");
    Team * t2 = new Team("Real Madrid", 1900, "Madrid");

    t1->print();
    t2->print();

    return 0;
}