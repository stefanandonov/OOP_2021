//
// Created by Stefan Andonov on 4/22/21.
//

#include<iostream>
#include<math.h>

using namespace std;

class Shape {
protected:
    double height;
public:
    Shape(double height = 1) {
        this->height = height;
    }

    virtual void print() {
        cout << " Area: " << area() << " Volume: " << volume() << endl;
    }

    virtual double volume() = 0;

    virtual double area() = 0;

    double getHeight() {
        return height;
    }
};

class Cylinder : public Shape { //base = circle
    double radius;
public:
    Cylinder(double height = 1, double radius = 1) : Shape(height) {
        this->radius = radius;
    }

    double area() override {
        return 2 * M_PI * radius * (height + radius);
    }

    double volume() override {
        return radius * radius * M_PI * height;
    }

    void print() override {
        cout << "CYLINDER";
        Shape::print();
    }

    double getRadius() {
        return radius;
    }

};

class Cone : public Shape {
    double radius;
public:
    Cone(double height = 1, double radius = 1) : Shape(height) {
        this->radius = radius;
    }

    double area() override {
        return M_PI * radius * (radius + sqrt(height * height + radius * radius));
    }

    double volume() override {
        return M_PI * radius * radius * height / 3;
    }

    void print() override {
        cout << "CONE";
        Shape::print();
    }

    double getRadius() {
        return radius;
    }
};

class Cuboid : public Shape {
    double a, b;
public:
    Cuboid(double height, double a, double b) : Shape(height), a(a), b(b) {}

    double area() override {
        return 2 * a * b + 2 * a * height + 2 * b * height;
    }

    double volume() override {
        return a * b * height;
    }

    void print() override {
        cout << "CUBOID";
        Shape::print();
    }

};

void maxVolume(Shape *array[], int n) {
    Shape *max = array[0];
    for (int i = 1; i < n; i++) {
        if (array[i]->volume() > max->volume()) {
            max = array[i];
        }
    }
    max->print();
}

double getRadius(Shape *s) {
    Cuboid *c = dynamic_cast<Cuboid *>(s);
    if (c != 0) { //has base circle
        Cylinder *c1 = dynamic_cast<Cylinder *>(s);
        if (c1 != 0)
            return c1->getRadius();
        else {
            Cone *c = dynamic_cast<Cone *>(s);
            return c->getRadius();
        }
    } else {
        return -1;
    }
}

int numberOfShapesWithoutCircleBase (Shape *array[], int n) {
    int count = 0;
    for (int i=0;i<n;i++) {
        if (getRadius(array[i])==-1)
            ++count;
    }
    return count;
}

int main() {
//    Shape * sh1 = new Cylinder(2,4);
//    Shape * sh2 = new Cone(2,4);
//    Shape * sh3 = new Cuboid(2,3,4);
//
//    sh1->print();
//    sh2->print();
//    sh3->print();

    int n;
    cin >> n;
    Shape **shapes = new Shape *[n];
    for (int i = 0; i < n; i++) {
        int type;
        cin >> type;
        double height, radius, a, b;
        switch (type) { //cylinder
            case 0:
                cin >> height >> radius;
                shapes[i] = new Cylinder(height, radius);
                break;
            case 1: //cone
                cin >> height >> radius;
                shapes[i] = new Cone(height, radius);
                break;
            case 2: //cuboid
                cin >> height >> a >> b;
                shapes[i] = new Cuboid(height, a, b);
                break;
        }
        shapes[i]->print();
    }

    maxVolume(shapes, n);
    cout<<"No circle based shapes: "<<numberOfShapesWithoutCircleBase(shapes, n);



    return 0;
}