#include<iostream>

using namespace std;

class Product {
protected:
    char name[50];
    double price;
public:
    Product(char *name = "", double price = 0) {
        strcpy(this->name, name);
        this->price = price;
    }
};

class Discount { //abstract class
public:
    virtual double getPrice() = 0;
    virtual double getDiscountedPrice() = 0;
};

class FoodProduct : public Product, public Discount {
private:
    double calories;
public:
    FoodProduct(char *name = "", double price = 0, double calories = 0) : Product(name, price), Discount() {
        this->calories = calories;
    }

    double getPrice() override {
        return price;
    }

    double getDiscountedPrice() override { //5%
        return 0.95 * price; // (1*price - 0.
    }
};

class DigitalProduct : public Product, public Discount {
    double size; //size in MB
public:
    DigitalProduct(char *name = "", double price = 0, double size = 0) : Product(name, price), Discount() {
        this->size = size;
    }

    double getPrice() override {
        return price;
    }

    double getDiscountedPrice() override { //10%
        return price * 0.9;
    }
};

double totalDiscount(Discount **products, int n) {
    //Discount is abstracts class so we can onlu have a pointer to a Discount
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        cout << products[i]->getPrice() - products[i]->getDiscountedPrice() << endl;
        sum += (products[i]->getPrice() - products[i]->getDiscountedPrice());
    }
    return sum;
}

int main() {
    Discount **discounts = new Discount *[5];
    discounts[0] = new DigitalProduct("DVD", 200, 4092);
    discounts[1] = new DigitalProduct("CD", 100, 1024);
    discounts[2] = new FoodProduct("pizza", 240, 400);
    discounts[3] = new FoodProduct("sandwich", 120, 300);
    discounts[4] = new FoodProduct("hamburger", 150, 500);

    cout << totalDiscount(discounts, 5);
    return 0;
}