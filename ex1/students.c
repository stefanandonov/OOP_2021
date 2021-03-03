//
// Created by Stefan Andonov on 2/25/21.
//

#include<stdio.h>
#include<ctype.h>
#include<string.h>

typedef struct {
    char firstName [50];
    char lastName [50];
    int ID;
    int totalPoints;
} student;

void swap(student *left, student *right);

student readStudent () {
    student result;
    int points[4];
    int i,sum=0;
    scanf("%s %s %d", result.firstName, result.lastName, &result.ID);
    for (i=0;i<4;i++) {
        scanf("%d", &points[i]);
        sum+=points[i];
    }
    result.totalPoints = sum;
    return result;
}

void capitalizeName (char * name) {
    name[0] = toupper(name[0]);
    for (int i=1;i<strlen(name);i++)
        name[i]=tolower(name[i]);
}

void printStudent (student s) {
    capitalizeName(s.lastName);
    capitalizeName(s.firstName);
    printf("%s %s %d %d\n", s.lastName, s.firstName, s.ID, s.totalPoints);
}

void bubbleSort(student arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)
        // Last i elements are already in place
        for (j = 0; j < n-i-1; j++)
            if (arr[j].totalPoints < arr[j+1].totalPoints)
                swap(&arr[j], &arr[j+1]);
}

void swap(student *left, student *right) {
    student temp = *left;
    *left = *right;
    *right = temp;
}

int main () {
    int i,n;
    scanf("%d", &n);
    student students[100];
    for (i=0;i<n;i++) {
        students[i]=readStudent();
    }

    bubbleSort(students, n);

    for (i=0;i<n;i++) {
        printStudent(students[i]);
    }

    return 0;
}