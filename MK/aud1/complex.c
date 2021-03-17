//
// Created by Stefan Andonov on 2/24/21.
//

#include<stdio.h>

typedef struct complex_number {
    float real;
    float imaginary;
} complex_number;

void printComplexNumber(complex_number c) { //2+3i; 2-3i;
    printf("%.2f%s%.2fi", c.real, c.imaginary > 0 ? "+" : "", c.imaginary);
}

int main() {
    complex_number c = {2.3, 4.5};
    printComplexNumber(c);
    return 0;
}

