//
// Created by Stefan Andonov on 5/5/21.
//
#include<iostream>
using namespace std;

class Product {
protected:
    char * name;
    double price;

    void copy (const Product & p) {
        this->name = new char [strlen(p.name)+1];
        strcpy(this->name, p.name);
        this->price = p.price;
    }

public:
    Product (char * name = "", int price = 0) {
        this->name = new char [strlen(name)+1];
        strcpy(this->name, name);
        this->price = price;
    }

    Product (const Product & p) {
        copy(p);
    }

    Product & operator = (const Product & p) {
        if (this!=&p) {
            delete [] this->name;
            copy(p);
        }
        return *this;
    }

    ~Product() {
        delete [] this->name;
    }
};

class Discount { //abstract class (interface) --> behavior
public:
    virtual double getPrice() = 0; //pure virtual
    virtual double getPriceWithDiscount() = 0;

    double getDiscount () {
        return getPrice() - getPriceWithDiscount();
    }
};

class FoodProduct: public Product, public Discount {
private:
    int calories;
public:
    FoodProduct (char * name = "", int price = 0, int calories = 0) : Product(name, price) {
        this->calories = calories;
    }

    FoodProduct(const FoodProduct & fp) : Product(fp){
        this->calories = fp.calories;
    }

    FoodProduct & operator = (const FoodProduct & fp) {
        if (this!=&fp) {
            delete [] this->name;
            copy(fp);
            this->calories = fp.calories;
        }
        return *this;
    }

    double getPrice() override {
        return price;
    }

    double getPriceWithDiscount() override {
        return price * 0.9;
    }
};

class DigitalProduct: public Product, public Discount {
private:
    double size;
public:
    DigitalProduct (char * name = "", int price = 0, double size = 0) : Product(name, price) {
        this->size = size;
    }

    DigitalProduct(const DigitalProduct & fp) : Product(fp){
        this->size = fp.size;
    }

    DigitalProduct & operator = (const DigitalProduct & fp) {
        if (this!=&fp) {
            delete [] this->name;
            copy(fp);
            this->size = fp.size;
        }
        return *this;
    }

    double getPrice() {
        return price;
    }

    double getPriceWithDiscount() {
        return price * 0.95;
    }

};

double total_discount (Discount ** products, int n) {//discount sum
    double sum = 0;
    for (int i=0;i<n;i++) {
        sum+=products[i]->getDiscount();
    }
    return sum;
}

int main () {

    Discount ** discounts = new Discount * [3];
    discounts[0] = new FoodProduct("pizza", 250, 200); //-->25
    discounts[1] = new DigitalProduct("CD", 50, 1024); // --> 2.5
    discounts[2] = new FoodProduct("croissant", 50, 40); // --> 5

    cout<<total_discount(discounts, 3);
    return 0;
}