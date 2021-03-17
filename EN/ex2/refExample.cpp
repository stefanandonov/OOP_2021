//
// Created by Stefan Andonov on 3/4/21.
//

#include <iostream>

using namespace std;

void swap (int & a, int & b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int a = 5;
    int &refA = a;
    int b = 6;
    cout << a << " " << b <<endl;
    swap(a,b);
    cout << a << " " << b;
    return 0;
}