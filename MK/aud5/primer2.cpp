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
    Team(char *name = "", int year = 1990, char *city = "") {
        strcpy(this->name, name);
        strcpy(this->city, city);
        this->year = year;
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

    char *getName() {
        return name;
    }

};

class Match {
    Team *host;
    Team *guest;
    int hostGoals;
    int guestGoals;

public:
    Match(Team *host, Team *guest, int hostGoals, int guestGoals) {
        this->host = host;
        this->guest = guest;
        this->hostGoals = hostGoals;
        this->guestGoals = guestGoals;
    }

    bool isTip(char tip) {
        switch (tip) {
            case '1':
                return this->hostGoals>this->guestGoals;
            case '2':
                return this->guestGoals>this->hostGoals;
            default: //'X'
                return this->guestGoals==this->hostGoals;
        }
    }

};


int main() {
    Team * t1 = new Team("Barca", 1890, "Barcelona");
    Team * t2 = new Team("Real Madrid", 1900, "Madrid");

    Match m (t1,t2, 5,6);

    cout<<m.isTip('1')<<endl;
    cout<<m.isTip('2')<<endl;
    cout<<m.isTip('X')<<endl;
    return 0;
}