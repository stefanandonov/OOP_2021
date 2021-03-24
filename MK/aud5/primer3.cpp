//
// Created by Stefan Andonov on 3/24/21.
//

#include<iostream>
//#include<cstring>

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

void sortTeam(Team *teams, int n) {
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (strcmp(teams[j].getName(),teams[j + 1].getName())>1)
                swap(teams[j], teams[j + 1]);
}

int main() {
    int n;
    cin >> n;
    char name[50];
    int year;
    char city[50];
    Team *teams = new Team[n];
    for (int i = 0; i < n; i++) {
        cin >> name >> city >> year;
        teams[i] = Team(name, year, city);
    }

    sortTeam(teams, n);

    for (int i = 0; i < n; i++) {
        teams[i].print();
    }
}