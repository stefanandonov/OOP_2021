//
// Created by Stefan Andonov on 3/18/21.
//

#include<iostream>

using namespace std;

class Student {
    int ID;
    char name[50];
    int test1, test2;
    int midterm1, midterm2;

public:
    Student(int ID = 111111,
            char name[50] = "Noname",
            int test1 = 0, int test2 = 0, int midterm1 = 0, int midterm2 = 0) {
        this->ID = ID;
        strcpy(this->name, name);
        this->test1 = test1;
        this->test2 = test2;
        this->midterm1 = midterm1;
        this->midterm2 = midterm2;
    }

    Student(const Student &other) {
        this->ID = other.ID;
        strcpy(this->name, other.name);
        this->test1 = other.test1;
        this->test2 = other.test2;
        this->midterm1 = other.midterm1;
        this->midterm2 = other.midterm2;
    }

    ~Student() {}

    double totalPoints() {
        return test1 / 2.0 + test2 / 2.0 + midterm1 * 0.45 + midterm2 * 0.45;
    }

    int grade() {
        double total = totalPoints();
//        if (total >= 90) return 10;
//        else if (total >= 80) return 9;
//        else if (total >= 70) return 8;
//        else if (total >= 60) return 7;
//        else if (total >= 50) return 6;
//        else return 5;
        int grade = int(total / 10) + 1; //100 -> 10+1 = 11
        if (grade < 5)
            grade = 5;
        if (grade > 10)
            grade = 10;
        return grade;
    }

    void print() {
        //id name total_points grade
        cout << ID << " " << name << " " << totalPoints() << " " << grade() << endl;
    }

    int compareTo(Student &s) {
        double diff = this->totalPoints() - s.totalPoints();
        if (diff != 0) {
            if (diff > 0)
                return 1;
            else return -1;
        } else return 0;
    }

    int getID() {
        return ID;
    }
};

class Course {
    char name[10];
    Student students[50];
    int nStudents;
public:
    Course(char *name = "") {
        nStudents = 0;
        strcpy(this->name, name);
    }

    Course(const Course &other) {
        strcpy(this->name, other.name);
        this->nStudents = other.nStudents;
        for (int i = 0; i < this->nStudents; i++) {
            students[i] = other.students[i];
        }
    }

    ~Course() {}

    void addStudent(Student &s) { //s1,s2,s3,s4,s5
        for (int i = 0; i < nStudents; i++) {
            if (students[i].getID()==s.getID())
                return ;
        }
        students[nStudents++] = s;
    }

    void sort() {
        for (int i = 0; i < nStudents - 1; i++)
            for (int j = 0; j < nStudents - i - 1; j++)
                if (students[j].compareTo(students[j + 1]) == -1)
                    swap(students[j], students[j + 1]);
    }

    void print() {
        sort();
        cout << name << endl;
        bool flag = true;
        for (int i = 0; i < nStudents; i++) {
            if (flag) {
                if (students[i].grade() == 5) {
                    cout << "--------------------------------" << endl;
                    flag = false;
                }
            }
            students[i].print();
        }
    }
};

int main() {
    Course c("OOP");
    char name[50];
    int ID, test1, test2, midterm1, midterm2;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ID >> name >> test1 >> test2 >> midterm1 >> midterm2;
        Student s(ID, name, test1, test2, midterm1, midterm2);
        //s.print();
        c.addStudent(s);
    }

    c.print();
    return 0;
}