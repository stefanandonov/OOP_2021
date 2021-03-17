//
// Created by Stefan Andonov on 3/3/21.
//

#include<iostream>
using namespace std;

void swap (int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main () {
    int a = 5;
    int b = 6;
    swap(a,b);
    cout<<a<<" "<<b;
    return 0;
}