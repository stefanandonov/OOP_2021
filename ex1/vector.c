//
// Created by Stefan Andonov on 2/25/21.
//

#include<stdio.h>

typedef struct vector {
    float x, y, z;
} vector;

void readVector(vector *v) {
    scanf("%f %f %f", &v->x, &v->y, &v->z);
}

void printVector(vector v) {
    printf("%.2f, %.2f, %.2f\n", v.x, v.y, v.z);
}

float dotProduct(vector left, vector right) {
    return left.x * right.x + left.y * right.y + left.z * right.z;
}

int main() {
    vector v;
    vector v1 = {3.4, 5.6, 7.8};
    readVector(&v);
    printVector(v);
    printVector(v1);
    printf("The dot product is %.2f", dotProduct(v,v1));

    return 0;
}
