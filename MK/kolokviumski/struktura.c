#include <stdio.h>
#include <string.h>

#define NEDELI 4
#define DENOVI 5

// ovde strukturata RabotnaNedela

typedef struct RabotnaNedela {
    int casovi[5];
    int rBr;
} RN;

// ovde strukturata Rabotnik

typedef struct Rabotnik {
    char ime[50];
    RN nedeli[4];
} R;

// ovde funkciite

int sumNaCasovite(RN nedela) {
    int sum = 0;
    for (int i = 0; i < DENOVI; i++) {
        sum += nedela.casovi[i];
    }
    return sum;
}

int sumNaCasoviteNaRabotnik(R rabotnik) {
    int sum = 0 ;
    for (int i=0;i<NEDELI;i++)
        sum+=sumNaCasovite(rabotnik.nedeli[i]);
    return sum;
}

int maxNedela(R *r) {
    int maxIdx = 0;
    int maxCasovi = 0;
    for (int i = 0; i < NEDELI; i++) {
        if (sumNaCasovite(r->nedeli[i]) > maxCasovi) {
            maxIdx = i;
            maxCasovi = sumNaCasovite(r->nedeli[i]);
        }
    }
    return maxIdx + 1;
}

void table(R *r, int n) {
    printf("Rab\t1\t2\t3\t4\tVkupno\n");
    for (int i=0;i<n;i++) {
        printf("%s\t%d\t%d\t%d\t%d\t%d\n", r[i].ime,
               sumNaCasovite(r[i].nedeli[0]),
               sumNaCasovite(r[i].nedeli[1]),
               sumNaCasovite(r[i].nedeli[2]),
               sumNaCasovite(r[i].nedeli[3]),
               sumNaCasoviteNaRabotnik(r[i]));
    }
}


int main() {
    int n;
    scanf("%d", &n);
    R rabotnici[n];
    int i;
    for (i = 0; i < n; ++i) {
        scanf("%s", rabotnici[i].ime);
        int j;
        for (j = 0; j < NEDELI; ++j) {
            int k;
            for (k = 0; k < DENOVI; ++k) {
                scanf("%d", &rabotnici[i].nedeli[j].casovi[k]);
            }

        }
    }
    printf("TABLE\n");
    table(rabotnici, n);
    printf("MAX NEDELA NA RABOTNIK: %s\n", rabotnici[n / 2].ime);
    printf("%d\n", maxNedela(&rabotnici[n / 2]));
    return 0;
}
