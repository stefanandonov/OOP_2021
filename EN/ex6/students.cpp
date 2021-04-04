//
// Created by Stefan Andonov on 4/1/21.
//

#include<iostream>

using namespace std;


class Student {
private:
    char *name;
    float average;  //5.0--> 10.0
    int studyYear; //1,2,3,4

    void copy(const Student &s) {
        this->average = s.average;
        this->studyYear = s.studyYear;
        this->name = new char[strlen(s.name) + 1];
        strcpy(this->name, s.name);
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
    }

    ~Student() {
        delete[] name;
    }

    Student &operator++() { //++student;
        studyYear++;
        return *this;
    }

    Student operator++(int) { //student++;
        Student copy(*this);
        ++studyYear;
        return copy;
    }

    friend ostream &operator<<(ostream &out, const Student &s) {
        return out << s.name << " Average: " << s.average << " Study year: " << s.studyYear << endl;
    }

    friend istream &operator>>(istream &in, Student &s) {
        return in >> s.name >> s.average >> s.studyYear;
    }

    bool operator>(const Student &s) {
        return this->average > s.average;
    }

    int getYear() {
        return studyYear;
    }

    bool operator>=(float average) {
        return this->average >= average;
    }

    float getAverage() {
        return average;
    }
};

class Group {
    Student *students;
    int n;

    void copy(const Group &g) {
        this->n = g.n;
        students = new Student[this->n];
//        strcpy(this->students, g.students); WRONG
        for (int i = 0; i < this->n; i++) {
            students[i] = g.students[i];
        }
    }

public:
    Group() {
        students = new Student[0];
        n = 0;
    }

    Group(const Group &g) {
        copy(g);
    }

    Group &operator=(const Group &g) {
        if (this != &g) {
            delete[] students;
            copy(g);
        }
        return *this;
    }

    ~Group() {
        delete[] students;
    }

    Group &operator+=(const Student &s) { //group+=student;
        Student *tmp = new Student[this->n + 1];
        for (int i = 0; i < this->n; i++) {
            tmp[i] = students[i];
        }
        tmp[this->n] = s;
        this->n++;
        delete[] students;
        students = tmp;
        return *this;
    }

    Group &operator++() {
        for (int i = 0; i < n; i++)
            ++students[i];
        return *this;
    }

    Group operator++(int) {
        Group copy(*this);
        for (int i = 0; i < copy.n; i++)
            copy.students[i]++;
        return copy;
    }

    friend ostream &operator<<(ostream &out, const Group &g) {
        for (int i = 0; i < g.n; i++)
            out << g.students[i];
        return out;
    }

    friend istream & operator >> (istream &in, Group & g) {
        int nn;
        in >> nn;
        for (int i=0; i < nn; i++) {
            Student s;
            in>>s;
            g+=s;
        }
        return in;
    }

    int countStudentsFromYear(int year) {
        int counter = 0;
        for (int i = 0; i < n; i++) {
            if (students[i].getYear() == year)
                ++counter;
        }
        return counter;
    }

    //delete all the students from a given study year
    Group &operator-=(int year) {
        int count = countStudentsFromYear(year);
        if (count != 0) {
            Student *tmp = new Student[n - count];
            for (int i = 0, j = 0; i < n; i++) {
                if (students[i].getYear() != year) {
                    tmp[j++] = students[i];
                }
            }
            delete[] students;
            students = tmp;
        }
        return *this;
    }

    void reward() {
        for (int i = 0; i < n; i++) {
            if (students[i] >= 9.0)
                cout << students[i];
        }
    }

    void highestAverage() {
        Student max = students[0];
        for (int i = 1; i < n; i++) {
            if (students[i]>max) // students[i].average > max.average
                max = students[i];
        }
        cout<<max.getAverage();
    }

    Student & operator [] (int idx) {
        return students[idx];
    }


};

int main() {
    Group group;
    cin>>group;

    cout<<group;
    cout<<++group;

    cout<<"REWARDED"<<endl;
    group.reward();
    cout<<"HIGHEST AVERAGE"<<endl;
    group.highestAverage();

    group-=3;

    ++(group[0]);

    cout<<group;


    return 0;
}
