//
// Created by Stefan Andonov on 5/10/21.
//

#include<iostream>
using namespace std;

class Product {
    char name [50];
    double basePrice;

public:
    static double MKD_TO_EUR;
    static double MKD_TO_USD;

    Product(char * name = "", double basePrice = 0)  {
        strcpy(this->name, name);
        this->basePrice = basePrice;
    }
    virtual float discount_price() = 0;

    float price() {
        return basePrice;
    }

    virtual void print_rule() = 0;

};

double Product::MKD_TO_EUR = 61.5;
double Product::MKD_TO_USD = 51.1;

class FoodProduct : public Product {
public:
    FoodProduct(char *name = "", double basePrice = 0) : Product(name, basePrice) {}

    float discount_price() override {
        return price();
    }

    void print_rule() override {
        cout<<"Food products don't have a discount"<<endl;
    }
};

class Drinks : public Product {
    bool alcohol;
    char brand [50];
    static const double ALCOHOL_DISCOUNT;
    static const double COCA_COLA_DISCOUNT;
public:
    Drinks(char *name = "", double basePrice = 0, bool alcohol = false, char * brand = "")
    : Product(name, basePrice), alcohol(alcohol) {
        strcpy(this->brand, brand);
    }

    float discount_price() override {
        if (alcohol && price()/MKD_TO_EUR > 20.0) {
            return price()*(1-ALCOHOL_DISCOUNT);
        }
        if (!alcohol && strcmp(brand,"Coca-Cola")==0)
            return price()*(1-COCA_COLA_DISCOUNT);
        return price();
    }

    void print_rule() override {
        cout<<"1. If it contains alcohol and price > 20EUR -> 5% discount"<<endl;
        cout<<"2. If its Coca-Cola -> 10% discount"<<endl;
    }
};

const double Drinks::ALCOHOL_DISCOUNT = 0.05;
const double Drinks::COCA_COLA_DISCOUNT = 0.1;

class Cosmetics : public Product {
public:
    Cosmetics(char *name = "", double basePrice = 0) : Product(name, basePrice) {}

    float discount_price() override {

    }
};

int main () {
    return 0;
}