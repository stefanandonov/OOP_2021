//
// Created by Stefan Andonov on 3/3/21.
//

/*Да се напише програма која од стандарден влез ќе чита податоци за n држави и
на екран ќе го отпечати името и презимето на претседателот на државата чиj
што главен град има најмногу жители. Податоци за држава:
• име
• претседател
• главен град
• број на жители.
Податоци за град:
• име
• број на жители.
Податоци за претседател:
• име
• презиме
• политичка партија.*/

#include<iostream>

using namespace std;

struct Politician {
    char name[50];
    char lastName[50];
    char party[50];

    void print() {
        cout << name << " " << lastName << " (" << party << ") "; // Donald Trump (R)
    }
};

Politician createPolitician() {
    Politician p{};
    cin >> p.name >> p.lastName >> p.party;
    return p;
}

struct City {
    char name[50];
    int population;

    void print() {
        cout << name << " (Population: " << population << ") ";
    }
};

City createCity() {
    City c{};
    cin >> c.name >> c.population;
    return c;
}

struct Country {
    char name[50];
    Politician president;
    City capital;
    int population;

    void print() {
        cout << name << " (Population: " << population << ") ";
        cout << "Capital: ";
        capital.print();
        cout << "President: ";
        president.print();
        cout << endl;
    }

    int compare(Country other) {
        int diff = capital.population - other.capital.population;
//        return diff == 0 ? 0 : (diff > 0 ? 1 : -1);
        if (diff > 0)
            return 1;
        else if (diff < 0)
            return -1;
        else return 0;
    }
};

Country createCountry() {
    Country c{};
    cin >> c.name;
    Politician p = createPolitician();
    c.president = p;
    City city = createCity();
    c.capital = city;
    cin >> c.population;
    return c;
}


int main() {
    int n;
    cin>>n;
    Country countries[50];
    for (int i=0;i<n;i++) {
        countries[i] = createCountry();
    }

    Country maxCountry = countries[0];
    for (int i=1;i<n;i++) {
        if (countries[i].compare(maxCountry) == 1) {
            maxCountry = countries[i];
        }
    }

    maxCountry.president.print();
    return 0;

}