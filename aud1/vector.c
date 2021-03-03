//
// Created by Stefan Andonov on 2/24/21.
//

#include<stdio.h>

typedef struct vector {
    float x;
    float y;
    float z;
} vector;

void readVector(vector *v) {
    scanf("%f %f %f", &v->x, &v->y, &v->z);
}

void printVector(vector v) {
    printf("[%.2f,%.2f,%.2f]", v.x, v.y, v.z);
}

float dotProduct(vector left, vector right) {
    return left.x * right.x + left.y * right.y + left.z * right.z;
}

vector vectorProduct(vector left, vector right) {
    vector v;
    v.x = left.y * right.z - left.z * right.y;
    v.y = left.z * right.x - left.x * right.z;
    v.z = left.x * right.y - left.y * right.x;
    return v;
}

int main() {

    vector v;
    vector v1 = {5.5, 6.7, 8.7};
    readVector(&v);

    printf("Dot product is %.2f\n", dotProduct(v,v1));
    vector result = vectorProduct(v,v1);
    printVector(result);
    return 0;
}