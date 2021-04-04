//
// Created by Stefan Andonov on 4/1/21.
//
#include<stdio.h>

typedef struct Driver {
    char name[100];
    int time;
} Driver;

int compare(Driver d1, Driver d2) {  //<0,0,>0
    return d1.time - d2.time;
}

typedef struct Race {
    char location[100];
    int nDrivers;
    Driver drivers[100];
} Race;

void swap(Driver *d1, Driver *d2) {
    Driver tmp = *d1;
    *d1 = *d2;
    *d2 = tmp;
}

void sort(Race *r) {
    int i, j;
    for (i = 0; i < r->nDrivers - 1; i++)
        for (j = 0; j < r->nDrivers - i - 1; j++)
            if (compare(r->drivers[j], r->drivers[j + 1]) > 0)
                swap(&r->drivers[j], &r->drivers[j + 1]);
}

void print (Race r) {
    /*
     *  Location-1 (14 Drivers)
        1. Isabella  9:48
        2. Sarah 14:27
        3. Ethan 15:02
     * */

    printf("%s (%d Drivers)\n", r.location, r.nDrivers);
    for (int i=0;i<3;i++) {
        printf("%d. %s %2d:%02d\n", i+1, r.drivers[i].name, r.drivers[i].time/60, r.drivers[i].time%60);
    }
}

int main() {
    int i, j, nRaces;
    scanf("%d", &nRaces);
    Race races[10];
    for (i = 0; i < nRaces; i++) {
        scanf("%s", races[i].location);
        scanf("%d", &races[i].nDrivers);
        for (j = 0; j < races[i].nDrivers; j++) {
            scanf("%s%d", races[i].drivers[j].name, &races[i].drivers[j].time);
        }
    }


    for (i = 0; i < nRaces; i++) {
        sort(&races[i]);
        print(races[i]);
    }

    return 0;
}