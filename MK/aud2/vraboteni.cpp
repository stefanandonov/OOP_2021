//
// Created by Stefan Andonov on 3/3/21.
//

#include<iostream>

using namespace std;

struct Employee {
    char name [50];
    char lastName [50];
    double salary;

    void print () {
        cout << name << " " << lastName << " " << salary << endl;
    }

    void increaseSalary (float bonus)  {
        salary+=bonus;
    }
};

Employee employees [50];

Employee createEmployee () {
    Employee e{};
    cin>>e.name>>e.lastName>>e.salary;
    return e;
}

Employee & getEmployee (int index) {
    return employees[index];
}

int main () {
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        employees[i] = createEmployee();
    }

    for (int i=0;i<n;i++)
        employees[i].print();

    getEmployee(1).print();
    getEmployee(1).increaseSalary(10000);
    getEmployee(1).print();
    return 0;
}