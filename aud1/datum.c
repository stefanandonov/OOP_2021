//
// Created by Stefan Andonov on 2/24/21.
//

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

typedef struct date {
    int day;
    int month;
    int year;
} date;

void readDate(date *d) {
    scanf("%d %d %d", &d->day, &d->month, &d->year);
}

void printDate(date d) {
    printf("%02d.%02d.%04d\n", d.day, d.month, d.year);
}

int daycmp(date left, date right) {
    if (left.day > right.day)
        return 1;
    else if (left.day < right.day)
        return -1;
    else
        return 0;
}

int monthcmp(date left, date right) {
    if (left.month > right.month)
        return 1;
    else if (left.month < right.month)
        return -1;
    else
        return daycmp(left, right);
}

int yearcmp(date left, date right) {
    if (left.year > right.year)
        return 1;
    else if (left.year < right.year)
        return -1;
    else
        return monthcmp(left, right);
}

int datecmp(date left, date right) {
    return yearcmp(left, right);
}

int diff(date left, date right) {
    int days = abs(left.day - right.day);
    int months = left.month - right.month;
    int years = abs(left.year - right.year);
    return days + months * 30 + years * 365;
}


int main() {
    date d1;
    date d2;
    date d3;
    readDate(&d1);
    readDate(&d2);
    readDate(&d3);

    printf("Comparing d1 and d2\n");
    printDate(d1);
    printDate(d2);
    printf("%d\n", datecmp(d1, d2));
    printf("Difference between is %d days\n", diff(d1,d2));

    printf("Comparing d1 and d3\n");
    printDate(d1);
    printDate(d3);
    printf("%d\n", datecmp(d1, d3));
    printf("Difference between is %d days\n", diff(d1,d3));

    printf("Comparing d2 and d3\n");
    printDate(d2);
    printDate(d3);
    printf("%s\n", datecmp(d2, d3) == 0 ? "Same dates" : (datecmp(d2, d3) == 1 ? "The left is greater then the right"
                                                                               : "The right is greater then the left"));
    printf("Difference between is %d days\n", diff(d2,d3));

    return 0;
}