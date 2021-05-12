//
// Created by Stefan Andonov on 5/12/21.
//

#include<iostream>

using namespace std;

class NegativeValueException {
    float negativePrice;
public:
    NegativeValueException(float negativePrice) : negativePrice(negativePrice) {}

    void showMessage() {
        cout << "Negative price (" << negativePrice << ") is not valid!" << endl;
    }
};

class Product {
protected:
    char name[50];
    float basePrice; // vo MKD
public:
    static float EUR_TO_MKD;
    static float USD_TO_MKD;

    Product(char *name = "", float price = 0) {
        strcpy(this->name, name);
        this->basePrice = price;
    }

    virtual float discount_price() = 0;

    float price() {
        return basePrice;
    }

    virtual void print_rule() = 0;

    void changePrice(float newPrice) {
        if (newPrice < 0) {
            throw NegativeValueException(newPrice);
        }
        this->basePrice = newPrice;
    }

};

float Product::EUR_TO_MKD = 61.5;
float Product::USD_TO_MKD = 51.3;

class FoodProduct : public Product {
public:
    FoodProduct(char *name = "", float price = 0) : Product(name, price) {}

    float discount_price() override {
        return price();
    }

    void print_rule() override {
        cout << "No discount here" << endl;
    }
};

class Drinks : public Product {
private:
    bool alcohol;
    char brand[50];
public:
    static const float ALCOHOL_DISCOUNT;
    static const float COCA_COLA_DISCOUNT;

    Drinks(char *name = "", float price = 0, bool alcohol = true, char *brand = "Skopsko") : Product(name, price) {
        this->alcohol = alcohol;
        strcpy(this->brand, brand);
    }

    float discount_price() override {
        if (alcohol && price() / EUR_TO_MKD > 20.0) {
            return price() * (1 - ALCOHOL_DISCOUNT); //price() - price()*ALCOHOL_DISCOUNT;
        }
        if (!alcohol && strcmp(brand, "Coca-Cola") == 0) {
            return price() * (1 - COCA_COLA_DISCOUNT); ////price() - price()*COCA_COLA_DISCOUNT;
        }
        return price();
    }

    void print_rule() override {
        cout << "1. If its alcoholic --> 5% discount" << endl;
        cout << "2. If its not alcoholic and it's Coca-Cola --> 10% discount" << endl;
    }
};

const float Drinks::ALCOHOL_DISCOUNT = 0.05;
const float Drinks::COCA_COLA_DISCOUNT = 0.1;

class Cosmetics : public Product {
public:

    Cosmetics(char *name = "", float price = 0) : Product(name, price) {

    }

    float discount_price() override { //50000
        if (price() / USD_TO_MKD > 20) {
            return price() * 0.86;
        } else if (price() / EUR_TO_MKD > 5) {
            return price() * 0.88;
        } else
            return price();
    }

    void print_rule() override {
        cout << "1. if price in USD is greater than 20$ --> 14% discount" << endl;
        cout << "2. if price in EUR is greater than 5EUR --> 12% discount" << endl;
    }
};

float totalPrice(Product **products, int size) {
    float sum = 0;
    for (int i = 0; i < size; i++) {
        cout << products[i]->price() << "\t" << products[i]->discount_price() << endl;
        sum += products[i]->discount_price();
    }
    return sum;
}

int main() {
    Product **products = new Product *[7];
    products[0] = new FoodProduct("pizza", 240);
    products[1] = new Drinks("whiskey", 5000, true, "blue label");
    products[2] = new Drinks("coca-cola zero", 70, false, "Coca-Cola");
    products[3] = new Cosmetics("maskara", 1300);
    products[4] = new Cosmetics("karmin", 400);
    products[5] = new Drinks("strumka", 50, false, "Strumka");
    products[6] = new Cosmetics("crveni ruzh", 150);
    cout << totalPrice(products, 7);


//    try {
//        products[4]->changePrice(-5);
//    } catch (NegativeValueException e) {
//        e.showMessage();
//    }

    for (int i = 0; i < 7; i++) {
        Cosmetics *cPtr = dynamic_cast<Cosmetics *>(products[i]);
        if (cPtr != nullptr) { //kastiranjeto e uspesno
            try {
                products[i]->changePrice(-5);
            } catch (NegativeValueException & e) {
                e.showMessage();
            }
        }
    }
    return 0;

}