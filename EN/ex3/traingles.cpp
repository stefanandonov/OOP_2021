//
// Created by Stefan Andonov on 3/11/21.
//

#include<iostream>

using namespace std;

#include<cmath>

class Triangle {
    int x, y, z;
public:
    Triangle(int _x = 1, int _y = 1, int _z = 1) {
        x = _x;
        y = _y;
        z = _z;
    }

    ~Triangle() {

    }

    int perimeter() {
        return x + y + z;
    }

    float area() {
        float s = float(perimeter()) / 2;
        return sqrt(s * (s - x) * (s - y) * (s - z));
    }

    void print () {
        cout<<"X: ";
        for (int i=0;i<x;i++) cout<<"-";
        cout<<endl;
        cout<<"Y: ";
        for (int i=0;i<y;i++) cout<<"-";
        cout<<endl;
        cout<<"Z: ";
        for (int i=0;i<z;i++) cout<<"-";
        cout<<endl;
        cout<<"Perimeter: "<<perimeter()<<" Area: "<<area()<<endl;
    }
};

int main() {
    int x,y,z;
    cin>>x>>y>>z;
    Triangle t (x,y,z);
    t.print();
    return 0;
}