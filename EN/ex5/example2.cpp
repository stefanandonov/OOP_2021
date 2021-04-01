//
// Created by Stefan Andonov on 3/25/21.
//

//
// Created by Stefan Andonov on 3/25/21.
//
#include<iostream>

using namespace std;

class Team {
private:
    char name[50];
    int year;
    char city[50];
public:
    Team(char *name = "", int year = 1800, char *city = "") {
        strcpy(this->name, name);
        this->year = year;
        strcpy(this->city, city);
    }

    Team(const Team &t) {
        strcpy(this->name, t.name);
        this->year = t.year;
        strcpy(this->city, t.city);
    }

    void print() {
        cout << name << " (" << year << ") " << " - " << city << endl;
    }
};

class Game {
private:
    Team *home;
    Team *away;
    int homeGoals;
    int awayGoals;
public:
    Game(Team *home = new Team(), Team *away = new Team(), int homeGoals = 0, int awayGoals = 0) {
        this->home = home;
        this->away = away;
        this->homeGoals = homeGoals;
        this->awayGoals = awayGoals;
    }

    Game(const Game &g) {
        this->home = g.home;
        this->away = g.away;
        this->homeGoals = g.homeGoals;
        this->awayGoals = g.awayGoals;
    }

    friend bool isPick(Game & g, char pick);

};

bool isPick(Game & g, char pick) { //1 home wins, 2 away wins, X draw
    if (pick == '1') {
        return g.homeGoals > g.awayGoals;
    } else if (pick == '2')
        return g.awayGoals > g.homeGoals;
    else
        return g.homeGoals == g.awayGoals;
}

int main() {
    Team *t = new Team("Barca", 1890, "Barcelona");
    Team *t1 = new Team("Real Madrid", 1899, "Madrid");
    t->print();
    t1->print();

    Game g (t,t1,5,0);

    cout<<isPick(g,'1');

    delete t;
    delete t1;
    return 0;
}