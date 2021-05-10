//
// Created by Stefan Andonov on 4/22/21.
//

#include<iostream>

using namespace std;

class HotelReservation {
protected:
    int numberOfDays;
    int numberOfPersons;
    char contact[50];
    const int pricePerDay = 25;
public:
    HotelReservation(int numberOfDays, int numberOfPersons, char *contact) : numberOfDays(numberOfDays),
                                                                             numberOfPersons(numberOfPersons) {
        strcpy(this->contact, contact);
    }

    HotelReservation(const HotelReservation &ht) {
        this->numberOfDays = ht.numberOfDays;
        this->numberOfPersons = ht.numberOfPersons;
        strcpy(this->contact, ht.contact);
    }

    virtual int price() {
        return numberOfPersons * numberOfDays * pricePerDay;
    }

    int price(int amount) {
        if (amount >= price()) {
            return amount - price();
        } else {
            cout << "You don't have money to stay in our hotel haha. You need to pay" << price() << endl;
            return -1;
        }
    }

};

class BBHotelReservation : public HotelReservation {
    const int breakfastPerPerson = 5;
public:
    BBHotelReservation(int numberOfDays, int numberOfPersons, char *contact)
            : HotelReservation(numberOfDays, numberOfPersons, contact) {

    }

    BBHotelReservation(const BBHotelReservation &bbHotelReservation) : HotelReservation(bbHotelReservation) {

    }

    int price() override {
        return HotelReservation::price() + numberOfDays * numberOfPersons * breakfastPerPerson;
    }
};

class Hotel {
    char name [50];
    int balance;
public:
    Hotel(char * name = "") {
        balance = 0;
        strcpy(this->name, name);
    }

    int reserve(HotelReservation &hr, int payment) {
        int change = hr.price(payment); //POLYMORPHISM
        if (change!=-1){
            balance+=hr.price(); //POLYMORPHISM
        }
        return change;
    }

    void print () {
        cout<<"Hotel: "<<name<<" "<<balance<<endl;
    }
};

int main() {
    Hotel hotel ("Balkan");

    HotelReservation * hr = new HotelReservation(5,2,"Stefan");
//    cout<<hr->price()<<endl;
//    cout<<hr->price(500)<<endl;
    HotelReservation * bbhr = new BBHotelReservation(5,2,"Stefan");
//    cout<<bbhr->price()<<endl;
//    cout<<bbhr->price(500)<<endl;

    cout<<hotel.reserve(*hr, 500)<<endl;
    hotel.print();
    cout<<hotel.reserve(*bbhr, 500)<<endl;
    hotel.print();
    return 0;
}