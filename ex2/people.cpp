//
// Created by Stefan Andonov on 3/4/21.
//

#include<iostream>

using namespace std;

struct Employee {
    char name[100];
    double salary;

    void print() {
        cout << "Employee: " << name << " Salary: " << salary << endl;
    }

    void increaseSalary (double amount) {
        salary+=amount;
    }
};

Employee createEmployee() {
    Employee e{};
    cin >> e.name >> e.salary;
    return e;
}

struct Company {
    char name[100];
    Employee manager;
    Employee employees[100];
    int nEmployees;

    void print() {
        cout << "Company: " << name << endl;
        cout << "Manager: ";
        manager.print();
        for (int i = 0; i < nEmployees; i++) {
            employees[i].print();
        }
    }

    Employee & getEmployee (int idx) {
        return employees[idx];
    }
};

Company createCompany() {
    Company c{};
    cin >> c.name;
    c.manager = createEmployee();
    cin >> c.nEmployees;
    for (int i = 0; i < c.nEmployees; i++) {
        c.employees[i] = createEmployee();
    }
    return c;
}

int main() {
    Company c = createCompany();
    c.print();
    Employee & e = c.getEmployee(2);
    e.increaseSalary(10000);
    c.print();
    return 0;
}
