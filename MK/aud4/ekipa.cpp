//
// Created by Stefan Andonov on 3/17/21.
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

    friend class Match;

};

class Match {
    Team host;
    Team guest;
    int hostGoals;
    int guestGoals;

public:
    Match(Team _host, Team _guest, int _hostGoals, int _guestGoals) {
        host = _host;
        guest = _guest;
        hostGoals = _hostGoals;
        guestGoals = _guestGoals;
    }

    bool rematch (Match other) {
        return strcmp(host.getName(), other.guest.getName()) == 0
               && strcmp(guest.getName(), other.host.getName()) == 0;
    }

    Team duel (Match other) {
        if (this->rematch(other)) {
            Team t1 = host; //other.guest
            Team t2 = guest; //other.host
            int goalsT1 = hostGoals + other.guestGoals;
            int goalsT2 = guestGoals + other.hostGoals;
            if (goalsT1>goalsT2)
                return t1;
            else if (goalsT2>goalsT1)
                return t2;
            else {
                cout<<"It's a tie."<<endl;
                return 0;
            }
        } else {
            cout<<"It's not a rematch"<<endl;
            return 0;
        }
    }

};





int main() {
    Team team("Real Madrid", 1902, "Madrid");
    Team team2("Barcelona", 1899, "Barcelona");
    Match m1 (team, team2, 4, 3); //implicitno povikuvanje na copy const za class Team
    Match m2 (team2, team, 3, 8);
    cout<<m1.rematch(m2); //impliciten povik na copu const i za Match i za Team
    Team winner = m1.duel(m2);
    winner.print();
    return 0;
}