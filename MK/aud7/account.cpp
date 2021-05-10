//
// Created by Stefan Andonov on 4/21/21.
//

#include<iostream>
using namespace std;

class DebitAccount {
protected:
    char name [100];
    char number [17];
    double balance;
public:
    DebitAccount(char * name = "noname", char * number = "1000000000000000", double balance = 0.0) {
        strcpy(this->name, name);
        strcpy(this->number, number);
        this->balance = balance;
    }

    DebitAccount (const DebitAccount & da) {
        strcpy(this->name, da.name);
        strcpy(this->number, da.number);
        this->balance = da.balance;
    }

    void report () {
        cout<<number<<" User: "<<name<<" Balance: "<<balance<<endl;
    }

    void deposit (double amount) {
        balance+=amount;
    }

    bool withdraw (double amount) {
        if (amount<=balance && amount>0) {
            balance-=amount;
            return true;
        } else {
            cout<<"Transaction now allowed"<<endl;
            return false;
        }
    }
};

class CreditAccount : public DebitAccount {
    double debt;
    double interest; //0.01 == 1% 0.1 = 10% 1.0 = 100%
    double minus;
    double limit;
public:
    CreditAccount(char * name = "noname", char * number = "1000000000000000", double balance = 0.0,
                  double interest = 0.01, double limit = 1000) : DebitAccount(name, number, balance){
        this->interest = interest;
        this->limit = limit;
        this->minus = 0;
        this->debt = 0;
    }

    CreditAccount (const CreditAccount & ca) : DebitAccount(ca){
        this->interest = ca.interest;
        this->limit = ca.limit;
        this->minus = ca.minus;
        this->debt = ca.debt;
    }

    void report () {
        DebitAccount::report();
        cout<<"Minus: "<<minus<<" Debt: "<<debt<<" Limit: "<<limit<<" Interest: "<<(interest*100)<<"%"<<endl;

    }

    void deposit (double amount) {
        if (debt>0) {
            double diff = amount-debt;
            if (diff>=0) { //debt = 100 amount = 1000; diff = 900; --> debt = 0; balance = 900;
                debt = 0;
                minus = 0;
                DebitAccount::deposit(diff);
            } else { //debt=1000, amount = 900;
                debt-=amount;
                minus-=amount;
            }
        }
    }

    bool withdraw (double amount) { //amount = 1000; balance = 10, limit 2000, minus = 0
        if (amount<=balance+limit-minus) {
            double diff = amount-balance;
            balance-=amount;
            if (balance<0)
                balance=0;
            if (diff>0) {
                minus+=diff;
                debt+=diff+(diff*interest);
            }
            return true;
        } else {
            cout<<"Transaction now allowed"<<endl;
            return false;
        }
    }

};

int main () {
    DebitAccount da("stefan", "10000000000000000", 1000);
    da.report();
    da.withdraw(10);
    da.report();
    CreditAccount ca("stefan", "10000000000000000", 1000);
    ca.report();
    ca.withdraw(1100); // --> balance = 0, minus 100, debt 101
    ca.report();
    ca.withdraw(900);
    ca.report();
    ca.withdraw(10);
    ca.report();
    ca.deposit(1000);
    ca.report();
    ca.deposit(1000);
    ca.report();
    return 0;
}