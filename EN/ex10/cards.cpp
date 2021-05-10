//
// Created by Stefan Andonov on 5/10/21.
//

#include<iostream>

using namespace std;

class OperationNotSupportedException {
    double difference;
public:
    OperationNotSupportedException(double difference) {
        this->difference = difference;
    }

    void showMessage() {
        cout << "You are trying to withdraw " << difference << " dollars more than you have on the account!" << endl;
    }
};

class Card {
protected:
    char ID[16];
    double balance;
public:
    Card(char *id = "123456789012345", double balance = 0.0) : balance(balance) {
        strcpy(this->ID, id);
    }

    Card(const Card &c) {
        strcpy(this->ID, c.ID);
        this->balance = c.balance;
    }

    virtual void print() {
        cout << "ID: " << ID << endl << "Balance: " << balance << endl;
    }

    void deposit(double amount) {
        balance += amount;
    }

    virtual void withdraw(double amount) {
        if (amount > balance) //illegal (so we should throw exception) 1000 1200 ->
            throw OperationNotSupportedException(amount - balance);
        balance -= amount;
    }
};

class Maestro : public Card {
public:
    static const double DISCOUNT;

    Maestro(char *id = "123456789012345", double balance = 0.0) : Card(id, balance) {

    }

    void print() override {
        cout << "Maestro card ";
        Card::print();
    }

    void withdraw(double amount) override { //1000 -> 950
        Card::withdraw(amount * (1 - DISCOUNT));
    }
};

const double Maestro::DISCOUNT = 0.05; //5%

class Master : public Card {
private:
    double limit;
public:
    static double NBRSM_DISCOUNT;
    static const double STANDARD_DISCOUNT;

    Master(char *id = "123456789012345", double balance = 0.0, double limit = 6000) : Card(id, balance) {
        this->limit = limit;
    }

    void print() override {
        cout << "Master card with limit: "<<limit<<" ";
        Card::print();
    }

    void withdraw(double amount) override {
        if (limit > 6000) {
            amount *= (1 - NBRSM_DISCOUNT);
        } else {
            amount *= (1 - STANDARD_DISCOUNT);
        }

        if (amount>balance+limit) { //-5000, 6000 I can withdraw 1000;
            throw OperationNotSupportedException(amount - balance - limit);
        } else {
            balance-=amount;
        }
    }


};

double Master::NBRSM_DISCOUNT = 0.1;
const double Master::STANDARD_DISCOUNT = 0.03;


class Register {
    int day, month, year;
    double cashPayments;
    double cardPayments;
public:
    Register(int day = 1, int month = 1, int year = 2021){
        this->day = day;
        this->month = month;
        this->year = year;
        cashPayments = 0;
        cardPayments = 0;
    }

    void pay (double cash) {
        cashPayments+=cash;
    }

    void pay (double amount, Card & card){
        try {
            card.withdraw(amount);
            cardPayments+=amount;
        } catch (OperationNotSupportedException & e) {
            e.showMessage();
        }
    }

    void print () {
        cout<<"Date: "<<day<<"."<<month<<"."<<year<<endl;
        cout<<"Cash payments: "<<cashPayments<<endl;
        cout<<"Card payments: "<<cardPayments<<endl;
    }
};

int main() {
//    Card * c = new Card();
//    c->print();
//    c->deposit(1000);
//
//    try{
//        c->withdraw(1200);
//    } catch (OperationNotSupportedException & e) {
//        e.showMessage();
//    }
//    try {
//        Card *maestro = new Maestro();
//        maestro->deposit(1000);
//        maestro->print();
//        maestro->withdraw(1000);
//        maestro->print();
//        maestro->withdraw(100); //95
//    } catch (OperationNotSupportedException &e) {
//        e.showMessage();
//    }

//    try{
//        Card *master = new Master();
//        master->deposit(1000);
//        master->print();
//        master->withdraw(7000);
//        master->print();
//        master->withdraw(210);
//        master->print();
//        master->withdraw(1000);
//        master->print();
//    } catch (OperationNotSupportedException & e) {
//        e.showMessage()  ;
//    }

    Register aRegister (10,5,2021);
    Card * debit = new Card("123", 10000);
    Card * maestro = new Maestro("1234", 12300);
    Card * master = new Master("1235", 40000);


    aRegister.pay(15000);

    aRegister.pay(9000, *debit);
    aRegister.print();
    debit->print();
    aRegister.pay(2000, *debit);
    aRegister.print();
    debit->print();

    return 0;
}