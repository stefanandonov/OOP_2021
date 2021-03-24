//
// Created by Stefan Andonov on 3/24/21.
//

#include<iostream>
using namespace std;

class Student {
    char * name;  //deklaracija na dinamicki alocirana niza od znaci
    int index;
    int grade;

    void copy (const Student & s) {
        this->name = new char [strlen(s.name)+1]; //inicijalizacija na din. al. memorija
        strcpy(this->name, s.name); //popolnuvame nizata so znaci
        this->index = s.index;
        this->grade = s.grade;
    }

public:
    Student (char * name = "", int index = 11111) {
        this->name = new char [strlen(name)+1]; //inicijalizacija na din. al. memorija
        strcpy(this->name, name); //popolnuvame nizata so znaci
        this->index = index;
        this->grade = 5;
    }
    //1. Zadolzitelno copy constructor
    Student (const Student & s) {
        copy(s);
    }

    //2. Zadolzitelno destruktor
    ~Student() {
        delete [] name;
    }

    //3. Operator za assignment =
    Student & operator = (const Student & s) {
       if (this!=&s){ //
            delete [] name;
            copy(s);
       }
       return *this;
    }

    Student & increaseGrade () {
        this->grade++;
        return *this;
    }

    void print () {
        cout<<name<<" "<<index<<" "<<grade<<endl;
    }
};

int main () {
    Student s ("Stefan", 151020);
    Student s1 = s; //copy constructor
    s = s1; //operator =

    return 0;
}