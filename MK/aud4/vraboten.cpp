//
// Created by Stefan Andonov on 3/17/21.
//
#include<iostream>
#include<cmath>

using namespace std;

class Date {
    int day;
    int month;
    int year;
public:
    Date(int _day = 1, int _month = 1, int _year = 2001) {
        day = _day;
        month = _month;
        year = _year;
    }

    Date(const Date &other) {
        day = other.day;
        month = other.month;
        year = other.year;
    }

    void print() {
        cout << day << "." << month << "." << year;
    }

    int compareTo(Date other) {
        if (year>other.year)
            return 1;
        else if (year<other.year)
            return -1;
        else {
            if (month>other.month)
                return 1;
            else if (month<other.month)
                return -1;
            else {
                if (day>other.day)
                    return 1;
                else if (day<other.day)
                    return -1;
                else return 0;
            }
        }
    }
};

class Employee {
    char name[20];
    int salary;
    Date dateOfBirth;
public:
    Employee(char *_name = "Name", int _salary = 10000, Date _dateOfBirth = Date()) {
        strcpy(name, _name);
        salary = _salary;
        dateOfBirth = _dateOfBirth;
    }

    void print() {
        cout << "Employee: " << name << " Salary: " << salary << " Date of birth: ";
        dateOfBirth.print();
        cout << endl;
    }

    int compareToBySalary(Employee &other) {
        int diff = salary - other.salary;
        return diff == 0 ? 0 : (diff > 0 ? 1 : -1);
    }

    int compareToByAge(Employee &other) {
        return dateOfBirth.compareTo(other.dateOfBirth);
    }
};

Employee &employeeWithHighestSalary(Employee *employees, int n) {
    //Baranje maximum od vrabotenite spored platata
    Employee & max = employees[0];
    for (int i=1;i<n;i++) {
        if (employees[i].compareToBySalary(max)>0)
            max = employees[i];
    }
    return max;
}

Employee &youngestEmployee(Employee *employees, int n) {
    //Baranje minimum od vrabotenite spored datumot na ragjanje
    Employee & max = employees[0];
    for (int i=1;i<n;i++) {
        if (employees[i].compareToByAge(max)>0)
            max = employees[i];
    }
    return max;
}

int main() {
    int n;
    cin >> n;
    Employee employees[50];
    char name[20];
    int salary;
    int day, month, year;
    for (int i = 0; i < n; i++) {
        cin >> name >> salary >> day >> month >> year;
        employees[i] = Employee(name, salary, Date(day, month, year));
    }

    for (int i = 0; i < n; i++) {
        employees[i].print();
    }

    employeeWithHighestSalary(employees, n).print();

    youngestEmployee(employees, n).print();

    return 0;
}