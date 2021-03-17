//
// Created by Stefan Andonov on 3/4/21.
//

#include<stdio.h>
#include<string.h>

typedef struct SkiLift {
    char name[15];
    int capacity;
    int inFunction; //0 if it's not, 1 if it is.
} SkiLift;

typedef struct SkiCenter {
    char name[20];
    char country[20];
    SkiLift skiLifts[20];
    int nSkiLift;
} SkiCenter;

int calculateCapacity(SkiCenter sc) {
    int i, sum = 0;
    for (i = 0; i < sc.nSkiLift; i++) {
        if (sc.skiLifts[i].inFunction) {
            sum += sc.skiLifts[i].capacity;
        }
    }
    return sum;
}

void print (SkiCenter sc) {
    printf("%s\n%s\n%d\n", sc.name, sc.country, calculateCapacity(sc));
}

void biggestCapacity(SkiCenter *sc, int n) {
    SkiCenter maxSkiCenter = sc[0];
    int i;
    for (i = 1; i < n; i++) {
        if (calculateCapacity(sc[i])>calculateCapacity(maxSkiCenter)) {
            maxSkiCenter = sc[i];
        } else if (calculateCapacity(sc[i])==calculateCapacity(maxSkiCenter)) {
            if (sc[i].nSkiLift > maxSkiCenter.nSkiLift) {
                maxSkiCenter = sc[i];
            }
        }
    }
    print(maxSkiCenter);
}


int main() {
    int i, n;
    scanf("%d", &n);
    SkiCenter skiCenters[10];
    for (i = 0; i < n; i++) {

        //scan the name, country and number of lifts
        scanf("%s %s %d", skiCenters[i].name, skiCenters[i].country, &skiCenters[i].nSkiLift);

        int j;
        //per each ski lift scan:
        //the name
        //the max number of users
        //wether is in function
        for (j = 0; j < skiCenters[i].nSkiLift; j++) {
            scanf("%s %d %d",
                  skiCenters[i].skiLifts[j].name,
                  &skiCenters[i].skiLifts[j].capacity,
                  &skiCenters[i].skiLifts[j].inFunction
            );
        }
    }

    //call the method biggestCapacity
    biggestCapacity(skiCenters, n);
    return 0;
}


