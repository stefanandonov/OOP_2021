//
// Created by Stefan Andonov on 3/31/21.
//

#include<iostream>

using namespace std;

class Student {
    char *name;
    float average;
    int studyYear;

    void copy(const Student &s) {
        this->name = new char[strlen(s.name) + 1];
        strcpy(this->name, s.name);
        this->average = s.average;
        this->studyYear = s.studyYear;
    }

public:
    Student(char *name = "", float average = 5.0, int studyYear = 1) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->average = average;
        this->studyYear = studyYear;
    }

    Student(const Student &s) {
        copy(s);
    }

    Student &operator=(const Student &s) {
        if (this != &s) {
            delete[] name;
            copy(s);
        }
        return *this;
    }//testoperatoriOOPStefan

    ~Student() {
        delete[] name;
    }

    //++student cout<<++student;
    Student &operator++() {
        ++studyYear;
        return *this;
    }

    //student++; cout<<student++; nema vednas da bide zgolemena godinata;
    Student operator++(int) {
        Student copy(*this);
        ++studyYear;
        return copy;
    }

    friend ostream &operator<<(ostream &out, const Student &s) {
        return out << s.name << " Average: " << s.average << " Study year: " << s.studyYear << endl;
    }

    friend istream &operator>>(istream &is, Student &s) {
        return is >> s.name >> s.average >> s.studyYear;
    }

    bool operator>(const Student &s) {
        return this->average > s.average;
    }

    friend class Group;
};

class Group {
    Student *students;
    int n;

    void copy (const Group & group) {
        this->n = group.n;
        this->students = new Student[this->n];
        for (int i=0;i<n;i++) {
            students[i]=group.students[i];
        }
    }
public:
    Group() {
        students = new Student[0];
        n = 0;
    }

    Group (const Group & g) {
        copy(g);
    }

    Group & operator = (const Group & g) {
        if (this!=&g) {
            delete [] students;
            copy(g);
        }
        return *this;
    }

    ~Group() {
        delete [] students;
    }

    Group & operator += (const Student & s) {
        Student * tmp = new Student [n+1];
        for (int i=0;i<n;i++)
            tmp[i]=students[i];
        tmp[n++]=s;
        delete [] students;
        students = tmp;
        return *this;
    }

    Group & operator ++ () {
        for (int i=0;i<n;i++)
            ++students[i];
        return *this;
    }

    friend ostream & operator << (ostream & out, const Group & g) {
        for (int i=0;i<g.n;i++)
            out<<g.students[i];
        return out;
    }

    friend istream & operator >> (istream & in, Group & g) {
        int nn;
        in >> nn;
        for (int i=0; i < nn; i++) {
            Student s;
            in>>s;
            g+=s;
        }
        return in;
    }

    void prize () {
        for (int i=0;i<n;i++)
            if (students[i].average==10.0)
                cout<<students[i];
    }

    void highestAverageGrade () {
        Student max = students[0];
        for (int i=0;i<n;i++) {
            if (students[i] > max) // students[i].average > max.average
                max = students[i];
        }
        cout<<max.average<<endl;
    }
};

int main() {
    Group g;
    cin>>g;
    cout<<++g;

    g.prize();
    g.highestAverageGrade();
    return 0;
}