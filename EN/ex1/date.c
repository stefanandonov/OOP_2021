//
// Created by Stefan Andonov on 2/25/21.
//

#include<stdio.h>
#include<stdlib.h>
typedef struct date{
    int day;
    int month;
    int year;
} date;

date readDate () {
    date d;
    scanf("%d %d %d", &d.day, &d.month, &d.year);
    return d;
}

void printDate(date d) {
    printf("%02d.%02d.%04d", d.day, d.month, d.year); //1.1.700 --> 01.01.0700
}

int datecmp (date left, date right) {
//    int diff = left.year-right.year;
//    if (diff==0) {
//        diff = left.month - right.month;
//        if (diff==0) {
//            diff = left.day - right.day;
//            if (diff==0)
//                return 0;
//            else return diff>0 ? 1 : -1;
//        } else return diff>0 ? 1 : -1;
//    } else return diff>0 ? 1 : -1;
    if (left.year>right.year)
        return 1;
    else if (left.year<right.year)
        return -1;
    else {
        if (left.month>right.month)
            return 1;
        else if (left.month<right.month)
            return -1;
        else {
            if (left.day>right.day)
                return 1;
            else if (left.day<right.day)
                return -1;
            else return 0;
        }
    }
}

int daySinceStart (date d) {
    //start date is 1.1.1000;
    int years = d.year-1000;
    int months = d.month-1;
    int days = d.day - 1;
    return years*365 + months*30 + days;
}

int diff (date left, date right) {
    return abs(daySinceStart(left) - daySinceStart(right));
}

int main () {
    int i,j,n;
    scanf("%d", &n);
    date dates[100];
    for (i=0;i<n;i++) {
        dates[i]=readDate();
    }

    for (i=0;i<n;i++) {
        for (j=0;j<n;j++) {
            printf("Difference between dates %d and %d is %d. ", i, j, diff(dates[i], dates[j]));
            if (datecmp(dates[i],dates[j])==1) {
                printf("Date %d is greater then date %d\n", i,j);
            } else if (datecmp(dates[i],dates[j])==-1) {
                printf("Date %d is less then date %d\n", i,j);
            } else {
                printf("Date %d is equal to date %d\n", i,j);
            }
        }
    }

    return 0;
}