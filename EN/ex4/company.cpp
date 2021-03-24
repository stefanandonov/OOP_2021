//
// Created by Stefan Andonov on 3/18/21.
//

#include<iostream>

using namespace std;

class Date {
private:
    int day, month, year;
public:
    Date(int day = 1, int month = 1, int year = 1900) {
        this->day = day;
        this->month = month;
        this->year = year;
    }

    Date(const Date &otherDate) {
        this->day = otherDate.day;
        this->month = otherDate.month;
        this->year = otherDate.year;
    }

    int compareTo(Date &other) { //using & to save object copies.
        if (this->year > other.year)
            return 1;
        else if (this->year < other.year)
            return -1;
        else {
            if (this->month > other.month)
                return 1;
            else if (this->month < other.month)
                return -1;
            else {
                if (this->day > other.day)
                    return 1;
                else if (this->day < other.day)
                    return -1;
                else return 0;
            }
        }
    }

    void print() {
        cout << day << "." << month << "." << year;
    }
};

class Employee {
    char name[20];
    double salary;
    Date dateOfBirth;

public:
    Employee(char name[20] = "Noname", double salary = 15678.50, Date dateOfBirth = Date()) {
        strcpy(this->name, name);
        this->salary = salary;
        this->dateOfBirth = dateOfBirth;
    }

    void print() {
        cout << "Employee: " << name << " Salary: " << salary << " Date of birth: ";
        dateOfBirth.print();
        cout << endl;
    }

    int compareBySalary(Employee &other) {
        double diff = this->salary - other.salary;
        if (diff != 0) {
            if (diff > 0)
                return 1;
            else
                return 0;
        } else
            return 0;
    }

    int compareByDateOfBirth(Employee & other) {
        return this->dateOfBirth.compareTo(other.dateOfBirth);
    }
};

Employee highestPaidEmployee(Employee *employees, int n) {
    //max of the employees where the employees are compared based on their salary
    Employee max = employees[0];
    for (int i = 1; i < n; i++) {
        if (employees[i].compareBySalary(max)>0)
            max = employees[i];
    }
    return max;
}

Employee youngestEmployee(Employee *employees, int n) {
    //max of the employees based on their date of birth
    Employee max = employees[0];
    for (int i = 1; i < n; i++) {
        if (employees[i].compareByDateOfBirth(max)>0)
            max = employees[i];
    }
    return max;
}

int main() {
    int n;
    cin >> n;
    Employee employees[50];
    char name[50];
    double salary;
    int day, month, year;
    for (int i = 0; i < n; i++) {
        cin >> name >> salary >> day >> month >> year;
        employees[i] = Employee(name, salary, Date(day, month, year));
    }

    highestPaidEmployee(employees, n).print();
    youngestEmployee(employees, n).print();
    return 0;
}