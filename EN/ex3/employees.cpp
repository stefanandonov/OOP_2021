//
// Created by Stefan Andonov on 3/11/21.
//

#include<iostream>

using namespace std;

enum Position {
    employee,
    manager,
    owner
};

class Employee {
private:
    char name[50];
    int salary;
    Position position;
public:
    Employee(char *_name = "Stefan", int _salary = 15000, Position _position = employee) {
        strcpy(name, _name);
        salary = _salary;
        position = _position;
    }

    void print() {
        cout << "Employee: " << name << " Salary: " << salary << " Position: ";
        switch (position) {
            case employee:
                cout << "Basic employee" << endl;
                break;
            case manager:
                cout << "Manager" << endl;
                break;
            case owner:
                cout << "Owner (CEO)" << endl;
                break;
        }
    }

    int getSalary() {
        return salary;
    }
};

void sortEmployees(Employee pEmployee[50], int n);

int main() {
    int n;
    cin >> n;
    Employee employees[50];
    char name[50];
    int salary;
    int position;
    for (int i = 0; i < n; i++) {
        cin >> name >> salary >> position;
        employees[i] = Employee(name, salary, Position(position));
    }

    sortEmployees(employees, n); //strlen(employees)NEVER!

    for (int i = 0; i < n; i++) {
        employees[i].print();
    }
    return 0;
}

void swap(Employee &e1, Employee &e2) {
    Employee temp = e1;
    e1 = e2;
    e2 = temp;
}

void sortEmployees(Employee employees[50], int n) {
    for (int i = 0; i < n - 1; i++)
        // Last i elements are already in place
        for (int j = 0; j < n - i - 1; j++)
            if (employees[j].getSalary() < employees[j + 1].getSalary())
                swap(employees[j], employees[j + 1]);
}
