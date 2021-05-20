//
// Created by Stefan Andonov on 5/20/21.
//

#include<iostream>
using namespace std;

template <typename T>
void mySwap (T & a, T & b){
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
void mySwap (T * t1, T * t2, int n) {
    for (int i=0;i<n;i++){
        T temp = t1[i];
        t1[i] = t2[i];
        t2[i] = temp;
    }
}


template <typename T> //to be a number (int, double, float, long) char
T myAbs (T a) {
    return a>=0 ? a : a*-1;
}



template <typename T>
void printTwoVariables (T a, T b){
    cout<<a<<" "<<b<<endl;
}

int main () {
    int a = 5, b = 6;
    cout<<"BEFORE SWAP"<<endl;
    printTwoVariables(a,b);
    mySwap(a,b);
    cout<<"AFTER SWAP"<<endl;
    printTwoVariables(a,b);


    double a1 = 5.6, b1= 6.5;
    cout<<"BEFORE SWAP"<<endl;
    printTwoVariables(a1,b1);
    mySwap(a1,b1);
    cout<<"AFTER SWAP"<<endl;
    printTwoVariables(a1,b1);


    a = -6;
    b = 7;
    cout<<myAbs(a)<<endl;
    cout<<myAbs(b)<<endl;
    a1 = -7.888;
    cout<<myAbs(a1)<<endl;

    char * str1 = "FINKI";
    char * str2 = "VESNA";

//    cout<<str1<<" "<<str2<<endl;
//    mySwap(str1, str2, 5);
//    cout<<str1<<" "<<str2<<endl;


    int array [] = {1,2,3,4,5};
    int array1 [] = {0,0,0,0,0};

    for (int i=0;i<5;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    for (int i=0;i<5;i++){
        cout<<array1[i]<<" ";
    }
    cout<<endl;

    mySwap(array, array1, 5);

    for (int i=0;i<5;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    for (int i=0;i<5;i++){
        cout<<array1[i]<<" ";
    }




    return 0;
}