//
// Created by Stefan Andonov on 4/1/21.
//

#include <iostream>
#include <cstring>

using namespace std;

class Pair {
    char *key;
    int value;

    void copy(const Pair &p) {
        this->key = new char[strlen(p.key) + 1];
        strcpy(this->key, p.key);
        this->value = p.value;
    }

public:
    Pair(char *key = "", int value = 1) {
        this->key = new char[strlen(key) + 1];
        strcpy(this->key, key);
        this->value = value;
    }

    Pair(const Pair &p) {
        copy(p);
    }

    Pair &operator=(const Pair &p) {
        if (this != &p) {
            delete[] key;
            copy(p);
        }
        return *this;
    }

    ~Pair() {
        delete[] key;
    }

    friend ostream &operator<<(ostream &out, const Pair &p) {
        return out << "'" << p.key << "' -> " << p.value << endl;
    }

    Pair &operator--() {
        --value;
        return *this;
    }

    Pair operator--(int) {
        Pair copy(*this);
        --value;
        return copy;
    }

    Pair operator*(const Pair &other) { //p = p1(this) * p2(other);
        int newValue = this->value * other.value;
        if (strlen(other.key) >= strlen(this->key))
            return Pair(other.key, newValue);
        else
            return Pair(this->key, newValue);
    }

    int getValue() {
        return value;
    }
};

class Collection {
    Pair *pairs;
    int n;

    void copy(const Collection &c) {
        this->n = c.n;
        this->pairs = new Pair[n];
        for (int i = 0; i < this->n; i++)
            this->pairs[i] = c.pairs[i];
    }

public:
    Collection() {
        n = 0;
        pairs = new Pair[0];
    }

    Collection(const Collection &other) {
        copy(other);
    }

    Collection &operator=(const Collection &c) {
        if (this != &c) {
            delete[] pairs;
            copy(c);
        }
        return *this;
    }

    ~Collection() {
        delete[] pairs;
    }

    Collection &operator+=(const Pair &p) {
        Pair *tmp = new Pair[n + 1];
        for (int i = 0; i < n; i++)
            tmp[i]=pairs[i];
        tmp[n++]=p;
        delete [] pairs;
        pairs = tmp;
        return *this;
    }

    friend ostream & operator << (ostream & out, const Collection & p) {
        out<<"Size: "<<p.n<<endl;
        for (int i=0;i<p.n;i++) {
            out<<p.pairs[i];
        }
        return out;
    }

    bool operator < (const Collection & c) {
        Pair product, cProduct;
        for (int i=0;i<n;i++) {
            product = product * pairs[i];
        }

        for (int i=0;i<c.n;i++) {
            cProduct = cProduct * c.pairs[i];
        }

        return product.getValue() < cProduct.getValue();
    }

    int greater(int value) {
        int count = 0;
        for (int i=0;i<n;i++) {
            if (pairs[i].getValue()>value)
                ++count;
        }
        return count;
    }

};


void read(char *k, float *v) {
    cin >> k;
    cin >> *v;
}

int main() {
    char key[50];
    float value;
    cout << "----- class Pair -----" << endl;
    read(key, &value);
    cout << "----- constructor -----" << endl;
    Pair p1(key, value);
    read(key, &value);
    Pair p2(key, value);
    Pair p3(p1);
    cout << "----- operator << -----" << endl;
    cout << p1;
    cout << p2;
    cout << "----- operator --(int) -----" << endl;
    cout << p1--;
    cout << p1;
    cout << "----- operator -- -----" << endl;
    cout << --p2;
    cout << "----- operator * -----" << endl;
    Pair p = p1 * p2;
    cout << "----- operator = -----" << endl;
    p3 = p;
    cout << p3;

    cout << "----- class Collection -----" << endl;
    cout << "----- constructor -----" << endl;
    Collection k;
    cout << "----- operator += -----" << endl;
    k += p1;
    k += p2;
    k += p3;
    cout << "----- operator << -----" << endl;
    cout << k;
    cout << "----- copy constructor -----" << endl;
    Collection k2(k);
    cout << "----- operator < -----" << endl;
    if (k < k2) {
        cout << "k < k2" << endl;
    } else {
        cout << "k >= k2" << endl;
    }
    k2 += p1;
    if (k < k2) {
        cout << "k < k2" << endl;
    } else {
        cout << "k >= k2" << endl;
    }
    cout << "----- greater -----" << endl;
    int x;
    cin >> x;
    int pp = k.greater(x);
    cout << pp;
    return 0;
}
