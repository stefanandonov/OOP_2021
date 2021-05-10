//
// Created by Stefan Andonov on 5/5/21.
//

#include<iostream>
#include<cstring>

using namespace std;

class Exception {
public:
    virtual void message() {}
};

class OperationNotSupportedException : public Exception {
private:
    double amount;
public:
    OperationNotSupportedException(double amount = 0) {
        this->amount = amount;
    }

    void message() override {
        cout << "You're trying to withdraw " << amount << "dollars more than you have" << endl;
    }
};

class Card {
protected:
    char id[16];
    double balance;
public:
    Card(char *id = "111111111111111", double balance = 0.0) {
        strcpy(this->id, id);
        this->balance = balance;
    }

    void deposit(double amount) {
        balance += amount;
    }

    virtual void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
        } else {
            throw OperationNotSupportedException(amount - balance);
        }
    }

    void print() {
        cout << id << " Balance: " << balance << endl;
    }

};

class Master : public Card {
private:
    double limit;
public:
    static const double STANDARD_DISCOUNT;
    static double NBRM_DISCOUNT;

    Master(char *id = "111111111111111", double balance = 0.0, double limit = 6000) : Card(id, balance) {
        this->limit = limit;
    }

    void withdraw(double amount) override {

        if (limit > 6000) {
            Card::withdraw(amount * (1 - NBRM_DISCOUNT));
        } else {
            Card::withdraw(amount * (1 - STANDARD_DISCOUNT));
        }

    }

};

const double Master::STANDARD_DISCOUNT = 0.03;
double Master::NBRM_DISCOUNT = 0.1;

class Maestro : public Card {
public:
    static const float DISCOUNT;

    Maestro(char *id = "111111111111111", double balance = 0.0) : Card(id, balance) {

    }

    void withdraw(double amount) override {

        Card::withdraw(amount * (1 - DISCOUNT));

    }
};

const float Maestro::DISCOUNT = 0.05;


class Register {
    int day, month, year;
    double amountInCash;
    double amountInCards;

public:
    Register(int day = 1, int month = 1, int year = 2021) {
        this->day = day;
        this->month = month;
        this->year = year;
        this->amountInCards = 0;
        this->amountInCash = 0;
    }

    void payToRegister (double amount) {
        amountInCash+=amount;
    }

    void payToRegister (double amount, Card & card) {
        try{
            card.withdraw(amount);
            amountInCards+=amount;
        } catch (OperationNotSupportedException & e) {
            e.message();
        }
    }

    void show () {
        cout<<"Date: "<<day<<"."<<month<<"."<<year<<endl;
        cout<<"Cash: "<<amountInCash<<endl;
        cout<<"Cards: "<<amountInCards<<endl;
    }

};


int main() {

    Card * c1 = new Maestro("123", 1000);
    Card * c2 = new Master("1234",15000);

    Register r (5,5,2021);
//    r.show();


    r.payToRegister(1000);
    r.payToRegister(5000);
    r.show();
    r.payToRegister(900, *c1);
    r.payToRegister(13000, *c2);
    r.show();
    c1->print();
    c2->print();
    r.payToRegister(145, *c1);
    r.payToRegister(4000, *c2);
    r.show();
    c1->print();
    return 0;
}