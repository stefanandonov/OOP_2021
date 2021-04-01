//
// Created by Stefan Andonov on 3/25/21.
//

#include<iostream>

using namespace std;

class Array {
    int *array;
    int size;
    int capacity;

    void copy(const Array &a) {
        this->size = a.size;
        this->capacity = a.capacity;
        this->array = new int[this->capacity];
        //strcpy(this->array, a.array); HUGE MISTAKE!!!
        for (int i = 0; i < this->size; i++) {
            this->array[i] = a.array[i];
        }
    }

public:
    Array(int capacity = 10) {
        this->size = 0;
        this->array = new int[capacity];
        this->capacity = capacity;
    }

    Array(int *array, int size) {
        this->size = size;
        this->array = new int[2 * size];
        this->capacity = 2 * size;
        for (int i = 0; i < this->size; i++)
            this->array[i] = array[i];
    }

    //1 copy constructor
    Array(const Array &a) {
        copy(a);
    }

    //2 operator for assignment =
    Array &operator=(const Array &a) { //Array a; a = a;
        if (this != &a) {
            delete[] array;
            copy(a);
        }
        return *this;
    }

    //3 destructor
    ~Array() {
        delete[] array;
    }

    void add(int number) {
        if (this->size == this->capacity) {
            int *tmp = new int[2 * capacity];
            for (int i = 0; i < size; i++) {
                tmp[i] = array[i];
            }
            tmp[size++] = number;
            delete[] array;
            array = tmp;
            this->capacity *= 2;
        } else {
            array[size++] = number;
        }
    }

    void replaceAll (int a, int b) {
        for (int i=0;i<this->size;i++)
            if (this->array[i]==a)
                this->array[i]=b;
    }

    void deleteAll (int number) { //1,2,3,4,5,2,2,7 --> 1,3,4,5,7
        int * tmp = new int [this->capacity];
        int j = 0;
        for (int i=0;i<this->size;i++) {
            if (array[i]!=number) {
                tmp[j++] = array[i];
            }
        }
        delete[] array;
        array = tmp;
        size = j;
    }

    void print () {
        cout<<"Capacity: "<<capacity<<endl;
        cout<<"Size: "<<size<<endl;
        int percentage = int(float(size)/capacity * 100.0);
        for (int i=0;i<percentage;i++) {
            cout<<"|";
        }
        for (int i=0;i<100-percentage;i++) {
            cout<<".";
        }
        cout<<endl;
        cout<<"[";
        for (int i=0;i<size;i++) {
            if (i==size-1 || (i==0 && size==0)) {
                cout<<array[i];
            } else {
                cout<<array[i]<<", ";
            }
        }
        cout<<"]"<<endl;
    }
};

int main() {
    Array a;

    a.print();
    for (int i=1;i<=81;i++) {
        a.add(i%10);
    }
    a.print();

    a.deleteAll(0);
    a.print();
    return 0;

}