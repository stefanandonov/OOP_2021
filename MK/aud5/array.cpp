//
// Created by Stefan Andonov on 3/24/21.
//

#include<iostream>

using namespace std;

class Array {
private:
    int *array;
    int size;
    int capacity;

    void copy(const Array &other) {
        this->capacity = other.capacity;
        this->size = other.size;
        this->array = new int[this->capacity];
        for (int i = 0; i < this->size; i++)
            this->array[i] = other.array[i];
    }

public:
    Array(int capacity = 10) {
        this->capacity = capacity;
        this->size = 0;
        array = new int[this->capacity]; //
    }

    Array(const Array &other) {
        copy(other);
    }

    Array &operator=(const Array &other) {
        if (this != &other) {
            delete[] array;
            copy(other);
        }
        return *this;
    }

    ~Array() {
        delete [] array;
    }

    void add(int number) {
        if (this->size == this->capacity) {
            int *tmp = new int[2 * this->capacity];
            for (int i = 0; i < this->size; i++) {
                tmp[i] = array[i];
            }
            tmp[this->size] = number;
            this->size++;
            this->capacity *= 2;
            delete[] this->array;
            array = tmp;
        } else {
            this->array[this->size] = number; //stavame na posledna pozicija
            ++this->size; //zgolemuvame broj na elementi
        }
    }

    void change(int a, int b) {
        for (int i = 0; i < size; i++) {
            if (array[i] == a)
                array[i] = b;
        }
    }

    int countOccurrences(int number) {
        int counter = 0;
        for (int i = 0; i < size; i++) {
            if (array[i]==number)
                ++counter;
        }
        return counter;
    }

    void deleteAll(int number) {
        //1. presmetajte kolku elementi treba da izbrishete
        int occurrences = countOccurrences(number);
        if (occurrences!=0) {
            int * tmp = new int [this->capacity];
            for (int i=0, j=0; i<this->size; i++) {
                if (array[i]!=number) {
                    tmp[j++]=array[i];
                }
            }
            delete [] array;
            array = tmp;
            size-=occurrences;
        }
    }

    void print() {
        cout << "Capacity: " << capacity << endl;
        cout << "Size: " << size << endl;
        for (int i = 0; i < size; i++) {
            if (i == size - 1) {
                cout << array[i] << endl;
            } else {
                cout << array[i] << ", ";
            }
        }
    }


};

int main() {
    Array a; //default konstruktor kapacitet 10
    for (int i = 0; i <= 99; i++) {
        a.add(i%10);
    }

    Array a1 (a);
//    a.print();
    a.deleteAll(0);
    a1.deleteAll(1);
    a.print();
    a1.print();

    return 0;
}