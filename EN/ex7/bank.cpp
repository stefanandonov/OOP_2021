//
// Created by Stefan Andonov on 4/15/21.
//

#include<iostream>

using namespace std;

class DebitAccount {
protected:
    char owner[50];
    char number[17];
    double balance;
public:
    DebitAccount(char *owner = "some owner", char *number = "1000000000000001", double balance = 0.0) {
        strcpy(this->owner, owner);
        strcpy(this->number, number);
        this->balance = balance;
    }

    DebitAccount(const DebitAccount &db) {
        strcpy(this->owner, db.owner);
        strcpy(this->number, db.number);
        this->balance = db.balance;
    }

    void report() {
        cout << number << " Owner: " << owner << " Balance: " << balance << endl;
    }

    void deposit(double amount) {
        balance += amount;
    }

    bool withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            return true;
        } else {
            cout << "Not sufficient balance on your account!!" << endl;
            return false;
        }
    }
};

class CreditAccount : public DebitAccount {
private:
    double limit;
    double minus; //how much money for loan we have taken from the bank
    double debt; //how much money we owe to the bank (+interest)
    double interest; // 0.01;

public:
    CreditAccount(char *owner = "some owner", char *number = "1000000000000001", double balance = 0.0,
                  double limit = 1000, double interest = 0.01) : DebitAccount(owner, number, balance) {
        this->limit = limit;
        this->minus = 0.0;
        this->debt = 0.0;
        this->interest = interest;
    }

    CreditAccount(DebitAccount &da, double limit = 1000, double interest = 0.01) : DebitAccount(da) {
        this->limit = limit;
        this->minus = 0.0;
        this->debt = 0.0;
        this->interest = interest;
    }

    void report() {
        DebitAccount::report();
        cout << "Limit: " << limit << " Minus: " << minus << " Debt: " << debt << endl;
    }

    void deposit(double amount) { //minus: 100  debt: 101  deposit==150 --> minus=0, debt=0, balance+=49
        if (minus > 0 && debt > 0) {
            double diff = amount - debt;
            minus -= amount;
            debt -= amount;
            if (minus < 0)
                minus = 0;
            if (debt < 0)
                debt = 0;

            if (diff>0){
                balance+=diff;
            }
        } else {
            DebitAccount::deposit(amount);
        }
    }

    bool withdraw(double amount) {
        if (amount<=balance+limit-minus) { //100 b=50, l=60, m=11
            double diff = balance+limit - amount;
            balance-=amount;
            if (balance<0)
                balance=0;
            if (diff>0) {
                minus+=diff;
                debt+=(diff*(1+interest)); //100MKD, interest 0.01 --> debt+=100+1
            }
            return true;
        } else {
            cout << "Not sufficient balance on your account!!" << endl;
            return false;
        }
    }
};

int main() {
    DebitAccount acc("Stefan Andonov", "2000000000111111", 100000);
//    acc.report();
//    acc.withdraw(10);
//    acc.report();

    CreditAccount creditAccount(acc, 10000);
    creditAccount.report();
    creditAccount.withdraw(105000);
    creditAccount.report();
    creditAccount.withdraw(5000);
    creditAccount.report();
    creditAccount.withdraw(1);
    creditAccount.report();
    creditAccount.deposit(10050);
    creditAccount.report();

    return 0;
}
