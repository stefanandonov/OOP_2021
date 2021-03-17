//
// Created by Stefan Andonov on 3/11/21.
//

#include<iostream>
#include<cmath>

using namespace std;

class Point {
private:
    int x, y;
public:
//    Point() { //default , no arguments
//        cout<<"Default constructor is called"<<endl;
//        x = 0;
//        y = 0;
//    }

    Point(int _x = 0, int _y = 0) {
        cout << "Constructor with arguments is called" << endl;
        x = _x;
        y = _y;
    }

    ~Point() {
        cout << "Object is destroyed" << endl;
    }

    void print() {
        cout << "[" << x << ", " << y << "]" << endl;
    }

    //getters
    int getX() {
        return x;
    }

    int getY() {
        return y;
    }

    //setter
    void setX(int _x) {
        x = _x;
    }

    void setY(int _y) {
        y = _y;
    }

    double distance(Point p) {
        return sqrt((p.x - x) * (p.x - x) + (p.y - y) * (p.y - y));
    }
};

int main() {
    Point p; //default constructor
    Point p1(10, 10); //constructor with arguments
    Point p2(5, -5);
    p.print();
    p1.print();
    p1.setY(-10);
    p1.print();
    p2.print();
    cout<<p.distance(p1)<<endl;
    return 0;
}