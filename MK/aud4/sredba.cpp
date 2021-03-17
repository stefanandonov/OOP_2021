//
// Created by Stefan Andonov on 3/17/21.
//

#include<iostream>
#include<cmath>
using namespace std;

class Boy {
private:
    char firstName [50];
    char lastName [50];
    int age;
public:
    Boy(char * _firstName= "", char * _lastName ="", int _age = 18) {
        strcpy(firstName, _firstName);
        strcpy(lastName, _lastName);
        age = _age;
    }

    Boy (const Boy & boy) {
        cout<<"Boy copy constructor called"<<endl;
        strcpy(firstName, boy.firstName);
        strcpy(lastName, boy.lastName);
        age = boy.age;
    }

    void print () {
        cout<<"Boy: "<<firstName<<" "<<lastName<<" "<<age;
    }

    int getAge() {
        return age;
    }
};

class Girl {
//private:
    char firstName [50];
    char lastName [50];
    int age;
public:
    Girl(char * _firstName= "", char * _lastName ="", int _age = 18) {
        strcpy(firstName, _firstName);
        strcpy(lastName, _lastName);
        age = _age;
    }

    Girl (const Girl & girl) {
        cout<<"Girl copy constructor called"<<endl;
        strcpy(firstName, girl.firstName);
        strcpy(lastName, girl.lastName);
        age = girl.age;
    }

    void print () {
        cout<<"Girl: "<<firstName<<" "<<lastName<<" "<<age;
    }

    int getAge() {
        return age;
    }
};

class LoveDate {
    Boy boy;
    Girl girl;
public:
    LoveDate (Boy _boy, Girl _girl) {
        boy = _boy;
        girl = _girl;
    }

    void print () {
        cout<<"Date: ";
        boy.print();
        cout<<" ";
        girl.print();
        cout<<endl;
    }

    bool isMatch () {
        int diff = abs(boy.getAge() - girl.getAge());
//        if (diff<=5) avoid this!!
//            return true;
//        else
//            return false;
        return diff<=5;
    }
};
int main () {
    Boy boy ("Stefan", "Andonov", 24);
    Girl girl ("sdsdf", "sdfsasd", 25);

    Boy b;
    Boy b1 = b; //eksplicitno povikuvanje na copy-constructor

    LoveDate date (boy, girl); //implicitno copy constructorot
    date.print();

    if (date.isMatch()) {
        cout<<"They are a match. Good job Tinder"<<endl;
    } else {
        cout<<"They are not a match. You might go to jail!"<<endl;
    }
    return 0;
}