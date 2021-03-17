//
// Created by Stefan Andonov on 2/25/21.
//

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
    char name [50];
    int population;
} city;

typedef struct {
    char name [50];
    char party [50];
} president;

typedef struct {
    char name [50];
    president  pres;
    city capital;
    int population;
} country;

city readCity () {
    city res;
    scanf("%s %d", res.name, &res.population);
    return res;
}

void printCity(city c) {
    printf("%s (Population: %d)", c.name, c.population);
}

president readPresident () {
    president res;
    scanf("%s %s", res.name, res.party);
    return res;
}

void printPresident(president p) {
    printf("%s (%s)", p.name, p.party);
}

country readCountry () {
    country c;
    scanf("%s", c.name);
    c.pres = readPresident();
    c.capital = readCity();
    scanf("%d", &c.population);
    return c;
}

void printCountry (country c) {
    printf("Country: %s (%d) Capital: ", c.name, c.population);
    printCity(c.capital);
    printf(" President: ");
    printPresident(c.pres);
}

int countrycmp (country left, country right) {
    int diff = left.capital.population - right.capital.population;
    return diff != 0 ? diff/abs(diff) : 0;
//    if (left.capital.population>right.capital.population)
//        return 1;
//    else if (left.capital.population < right.capital.population)
//        return -1;
//    else return 0;
}

country max (country * countries, int n) {
    country max = countries[0];
    int i;
    for (i=1;i<n;i++) {
        if (countrycmp(countries[i], max)==1) {
            max = countries[i];
        }
    }
    return max;
}

int main () {
    int i, n;
    scanf("%d", &n);
    country countries [100];
    for (i=0;i<n;i++) {
        countries[i] = readCountry();
    }

    printPresident(max(countries,n).pres);

    return 0;
}