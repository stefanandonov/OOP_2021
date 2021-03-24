//
// Created by Stefan Andonov on 3/18/21.
//

#include<iostream>

using namespace std;

enum Gender {
    M,
    F
};

class Mate {
    char name[50];
    int age;
    Gender gender;
public:
    Mate(char name[50] = "", int age = 18, Gender gender = F) {
        strcpy(this->name, name);
        this->age = age;
        this->gender = gender;
    }

    Mate(const Mate &other) {
        cout << "Copy constructor for Mate is called" << endl;
        strcpy(this->name, other.name);
        this->age = other.age;
        this->gender = other.gender;
    }

    void print() {
        cout << name << " (" << age << ") " << (gender == M ? "Male " : "Female ");
        cout << "Sum of ascii letters from name: " << sumOfAscii() << endl;
    }

    int sumOfAscii() {
        int sum = 0;
        for (int i = 0; i < strlen(name); i++) {
            sum += int(name[i]);
        }
        return sum;
    }
};

class LoveDate {
    Mate m1, m2;
public:
    LoveDate(Mate m1 = Mate(), Mate m2 = Mate()) {
        this->m1 = m1;
        this->m2 = m2;
    }

    void print() {
        m1.print();
        m2.print();
        cout << (isSuccess() ? "Success" : "Failure") << endl;
    }

    bool isSuccess() {
        return (m1.sumOfAscii() + m2.sumOfAscii()) % 2 == 0;
    }
};

int main() {
    Mate m("Stefan Andonov", 24, M);
     //explicitly Mate m1 = m;
    Mate f("Adriana Lima", 25, F);


    Mate m1(m); //1 explicit call
    LoveDate loveDate (m,m1); //2 implicit calls = 3

    loveDate.print();

    return 0;
}