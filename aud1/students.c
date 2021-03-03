//
// Created by Stefan Andonov on 2/24/21.
//

#include<stdio.h>
#include <ctype.h>
#include<string.h>

typedef struct student {
    char name[50];
    char lastName[50];
    int index;
    int points;
} student;

void readStudent(student * s) {
    int points[4];
    scanf("%s %s %d %d %d %d %d", s->name, s->lastName, &s->index, &points[0], &points[1], &points[2], &points[3]);
    int sum = 0;
    for (int i = 0; i < 4; i++)
        sum += points[i];
    s->points = sum;
}

void cleanName(char *name) {
    name[0] = toupper(name[0]);
    int i;
    for (i = 1; i < strlen(name); i++)
        name[i] = tolower(name[i]);
}

void printStudent(student s) {
    cleanName(s.name);
    cleanName(s.lastName);
    printf("%s\t%s\t%d\t%d\n", s.lastName, s.name, s.index, s.points);
}

void swap(student *s1, student *s2) {
    student temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

int studentcmp(student left, student right) {
    int diff = left.points - right.points;
    if (diff==0)
        return diff;
    else
        return diff>0 ? 1 : -1;
//    if (diff < 0)
//        return -1;
//    else if (diff > 0)
//        return 1;
//    else return 0;
}

void sortStudent(student * students, int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (studentcmp(students[j+1], students[j])==1) {
                swap(&students[j+1], &students[j]);
            }
        }
    }
}

int main() {
    student students[100];
    int i, n;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        readStudent(students + i);
    }
    sortStudent(students,n);
    for (i = 0; i < n; i++) {
        printStudent(students[i]);
    }

}