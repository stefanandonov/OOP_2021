//
// Created by Stefan Andonov on 5/10/21.
//

#include<iostream>

using namespace std;

class Exception {
public:
    virtual void showMessage() = 0;
};

class DivisionWithZeroException : public Exception {
public:
    void showMessage() override {
        cout << "Division with zero is not possible!!!" << endl;
    }
};

class MathOperation {
private:
    int x;
public:
    static int MULTIPLIER;
    static int DIVISOR;
    static int ADDEN;
    static const int SUBTRACTEN;

    MathOperation(int x = 1) {
        this->x = x;
    }

    static void setAdden(int a) {
        ADDEN = a;
    }

    static void setMultiplier(int multiplier) {
        MULTIPLIER = multiplier;
    }

    static void setDivisor(int divisor) {
        //where the problem could happen
        if (divisor == 0)
            throw DivisionWithZeroException();
        DIVISOR = divisor;
    }

//    static void setSubtracten(int subtracten) { CONST static member can't be changed
//        SUBTRACTEN = subtracten;
//    }

    void print() {
        cout << "Multiplication: " << x * MULTIPLIER << endl;
        cout << "Division: " << x / (DIVISOR * 1.0) << endl;
        cout << "Addition: " << x + ADDEN << endl;
        cout << "Difference: " << x - SUBTRACTEN << endl;
    }
};

int MathOperation::ADDEN = 5;
const int MathOperation::SUBTRACTEN = 6;
int MathOperation::DIVISOR = 2;
int MathOperation::MULTIPLIER = 3;

int main() {
    MathOperation mo1(5);
    MathOperation mo2(6);
//    mo1.print();
//    mo2.print();
    MathOperation::setAdden(10);
//    mo1.print();
//    mo2.print();

    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        int divisor;
        cin >> divisor;
        try {
            MathOperation::setDivisor(divisor); //THIS IS WHERE THE PROBLEM CAN HAPPEN}
            mo1.print();
            mo2.print();
        }
        catch (DivisionWithZeroException &e) {
            e.showMessage();
        }
    }
    return 0;
}