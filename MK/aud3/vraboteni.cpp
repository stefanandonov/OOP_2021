//
// Created by Stefan Andonov on 3/10/21.
//

#include<iostream>
#include<cstring>
#include<string.h>

using namespace std;

enum Type {
    employee, //0
    manager, //1
    owner //2
};

class Employee {
private:
    char name[10];
    int salary;
    Type type;
public:
    Employee(char *_name = "Stefan", int _salary = 15000, Type _type = employee) {
        strcpy(name, _name);
        salary = _salary;
        type = _type;
    }

    ~Employee() {

    }

    void print() {
        cout << "Employee: " << name << " Salary: " << salary << " Type: ";
        switch (type) {
            case employee:
                cout << "Basic" << endl;
                break;
            case manager:
                cout << "Manager" << endl;
                break;
            default:
                cout << "Owner" << endl;
        }
    }

    void setName(char _name[50]) {
        strcpy(name, _name);
    }

    void setSalary(int _salary) {
        salary = _salary;
    }

    void setType(Type _type) {
        type = _type;
    }

    int getSalary () {
        return salary;
    }

    int compareTo(Employee other) {
        int diff = salary - other.salary;
        return diff == 0 ? diff : (diff > 0 ? 1 : -1);
    }
};

void swap (Employee &e1, Employee &e2) {
    Employee tmp = e1;
    e1 = e2;
    e2 = tmp;
}

int main() {
    int n;
    cin >> n;
    Employee employees[50];
    char name[10];
    int salary;
    int type;
    for (int i = 0; i < n; i++) {
        cin >> name >> salary >> type; // Stefan 15000 0
        //employees[i] = Employee(name, salary, (Type)type);
        employees[i].setName(name);
        employees[i].setSalary(salary);
        employees[i].setType((Type) type);
    }

    //TODO sort employees by salary in descending order
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (employees[j].getSalary()<employees[j+1].getSalary())
                swap(employees[j], employees[j+1]);

    for (int i = 0; i < n; i++) {
        employees[i].print();
    }
    return 0;
}