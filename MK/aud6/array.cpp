//
// Created by Stefan Andonov on 3/24/21.
//

#include<iostream>

using namespace std;

class IndexOutOfBoundsException {
    int idx;
public:
    IndexOutOfBoundsException(int idx) : idx(idx) {}
    void printMessage () {
        cout<<"Index ["<<idx<<"] is out of bounds"<<endl;
    }
};

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
        delete[] array;
    }

    Array &operator+=(int number) {  //a+=5;
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
        return *this;
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
            if (array[i] == number)
                ++counter;
        }
        return counter;
    }

    Array &operator-=(int number) {
        //1. presmetajte kolku elementi treba da izbrishete
        int occurrences = countOccurrences(number);
        if (occurrences != 0) {
            int *tmp = new int[this->capacity];
            for (int i = 0, j = 0; i < this->size; i++) {
                if (array[i] != number) {
                    tmp[j++] = array[i];
                }
            }
            delete[] array;
            array = tmp;
            size -= occurrences;
        }
        return *this;
    }

    friend ostream &operator<<(ostream &out, const Array &a) { //cout<<a;
        out << "Capacity: " << a.capacity << endl;
        out << "Size: " << a.size << endl;
        for (int i = 0; i < a.size; i++) {
            if (i == a.size - 1) {
                out << a.array[i] << endl;
            } else {
                out << a.array[i] << ", ";
            }
        }
        return out;
    }

    int &operator[](int idx) { //10 elementi -> 0,1,2,3,4,5,6,7,8,9
        if (idx < 0 || idx >= size)
            throw IndexOutOfBoundsException(idx);
        return array[idx];
    }

    bool operator==(const Array &other) {
        if (this->size != other.size)
            return false;
        else {
            for (int i = 0; i < size; i++) {
                if (this->array[i] != other.array[i]) {
                    return false;
                }
            }
            return true;
        }
    }    //a1(this)==a2(other);

};

int main() {
    Array a; //default konstruktor kapacitet 10
    for (int i = 0; i <= 99; i++) {
        a += i % 10;
    }

    Array a1(a);
    cout << a;
    a -= 0;
    a1 -= 1;
    cout << a;
    cout << a1;

    try {
        a1[101] = 10;
        cout << a1;
    }
    catch (IndexOutOfBoundsException & e) {
        e.printMessage();
    }

    cout << (a == a1) << endl; //0 false
    Array a2(a);
    cout << (a == a2); // 1 true

    return 0;
}