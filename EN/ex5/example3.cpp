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

    friend void sort(Team *teams, int n);
};

void sort(Team *teams, int n) {
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (strcmp(teams[j].name, teams[j + 1].name)>0)
                swap(teams[j], teams[j + 1]);
}

int main() {
    int N;
    cin >> N;
    char name[50], city[50];
    int year;
    Team *teams = new Team[N];
    for (int i = 0; i < N; i++) {
        cin >> name >> year >> city;
        teams[i] = Team(name, year, city);
    }

    sort(teams, N);

    for (int i = 0; i < N; i++) {
        teams[i].print();
    }
    return 0;
}