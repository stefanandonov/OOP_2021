//
// Created by Stefan Andonov on 2/25/21.
//

#include<stdio.h>

typedef struct complex_number {
    float real;
    float imaginary;
} complex_number;

complex_number readComplexNumber() {
    complex_number c;
    scanf("%f %f", &c.real, &c.imaginary);
    return c;
}

void printComplexNumber(complex_number c) {
    printf("%.2f%+.2fi", c.real, c.imaginary);
}

complex_number sum (complex_number left, complex_number right) {
    complex_number result;
    result.real = left.real + right.real;
    result.imaginary = left.imaginary + right.imaginary;
    return result;
}

complex_number diff (complex_number left, complex_number right) {
    complex_number result;
    result.real = left.real - right.real;
    result.imaginary = left.imaginary - right.imaginary;
    return result;
}

int main() {
    complex_number c = readComplexNumber();
    printComplexNumber(c);
    return 0;
}