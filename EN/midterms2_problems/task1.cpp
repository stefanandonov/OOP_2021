#include <iostream>
#include <cstring>

using namespace std;

class MonthlyInvoice {
protected:
    char username[100];
    int userNumber;
    float basePrice;
    int gigabytes;

    void copy(const MonthlyInvoice &monthlyInvoice) {
        strcpy(this->username, monthlyInvoice.username);
        this->userNumber = monthlyInvoice.userNumber;
        this->basePrice = monthlyInvoice.basePrice;
        this->gigabytes = monthlyInvoice.gigabytes;
    }

public:
    MonthlyInvoice(char *username = "", int userNumber = 0, float basePrice = 0, int gigabytes = 0) {
        strcpy(this->username, username);
        this->userNumber = userNumber;
        this->basePrice = basePrice;
        this->gigabytes = gigabytes;
    }

    MonthlyInvoice(const MonthlyInvoice &monthlyInvoice) {
        copy(monthlyInvoice);
    }

    MonthlyInvoice &operator=(const MonthlyInvoice &mi) {
        if (this != &mi) {
            copy(mi);
        }
        return *this;
    }

    virtual double total_price() const {
        return basePrice;
    }

    MonthlyInvoice operator++(int) {
        MonthlyInvoice copy(*this);
        this->gigabytes += 1;
        return copy;
    }

    bool operator > (const MonthlyInvoice & mi) {
        return this->total_price() > mi.total_price();
    }
};


class BusinessInvoice : public MonthlyInvoice {
private:
    bool optics;
    int freeGigabytes;

    void copy(const BusinessInvoice &bi) {
        MonthlyInvoice::copy(bi);
        this->optics = bi.optics;
        this->freeGigabytes = bi.freeGigabytes;
    }

public:
    BusinessInvoice(char *username = "", int userNumber = 0, float basePrice = 0, int gigabytes = 0,
                    bool optics = false, int freeGigabytes = 0) : MonthlyInvoice(username, userNumber, basePrice,
                                                                                 gigabytes) {
        this->optics = optics;
        this->freeGigabytes = freeGigabytes;
    }

    BusinessInvoice(const BusinessInvoice &bi) {
        copy(bi);
    }

    BusinessInvoice &operator=(const BusinessInvoice &bi) {
        if (this != &bi) {
            copy(bi);
        }
        return *this;
    }

    int overTheFreeGigabytes () const {
        int overTheFree = 0;
        if (gigabytes > freeGigabytes) {
            overTheFree = gigabytes - freeGigabytes;
        }
        return overTheFree;
    }

    double total_price() const {


        if (optics)
            return basePrice * 1.5 + overTheFreeGigabytes() * 100.0;
        else
            return basePrice + overTheFreeGigabytes() * 100.0;
    }

    friend ostream & operator << (ostream & out, const BusinessInvoice & bi){
        out<<bi.userNumber<<" - "<<bi.username<<", "<<bi.basePrice<<endl;
        if (bi.optics){
            out<<"optical link, ";
        } else {
            out<<"cable link, ";
        }
        out<<bi.overTheFreeGigabytes()<<endl;
        return out;
    }


};

class PrivateInvoice : public MonthlyInvoice {
private:
    int *sizes;
    int n;

    void copy(const PrivateInvoice &pi) {
        MonthlyInvoice::copy(pi);
        this->n = pi.n;
        this->sizes = new int[this->n];
        for (int i = 0; i < this->n; i++) {
            this->sizes[i] = pi.sizes[i];
        }
    }

public:
    PrivateInvoice(char *username = "", int userNumber = 0, float basePrice = 0, int gigabytes = 0)
            : MonthlyInvoice(username, userNumber, basePrice, gigabytes) {
        sizes = new int[0];
        n = 0;
    }

    PrivateInvoice(const PrivateInvoice &pi) {
        copy(pi);
    }

    PrivateInvoice &operator=(const PrivateInvoice &pi) {
        if (this != &pi) {
            delete[] sizes;
            copy(pi);
        }
        return *this;
    }

    ~PrivateInvoice() {
        delete[] sizes;
    }

    int totalSizeOfMovies() const {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += sizes[i];
        }
        return sum;
    }

    double total_price() const  {
        return basePrice + gigabytes * 50.0 + totalSizeOfMovies() * 10.0;
    }

    int operator[](int idx) const {
        if (idx < 0 || idx >= n) {
            return -1;
        } else {
            return sizes[idx];
        }
    }

    PrivateInvoice &operator+=(int size) {
        int * tmp = new int [n+1];
        for (int i=0;i<n;i++){
            tmp[i] = sizes[i];
        }
        tmp[n++] = size;
        delete [] sizes;
        sizes = tmp;
        return *this;
    }

    friend ostream & operator << (ostream & out, const PrivateInvoice & pi) {
        out<<pi.userNumber<<" - "<<pi.username<<", "<<pi.basePrice<<endl;
        out<<pi.gigabytes<<endl;
        out<<pi.n<<", "<<pi.totalSizeOfMovies()<<endl;
        return out;
    }

    int getMoviesNo() {
        return n;
    }
};

MonthlyInvoice & biggestInvoice (MonthlyInvoice ** invoices, int n) {
    int maxIdx = 0;
    for (int i=0;i<n;i++) {
        if ((*invoices[i])>(*invoices[maxIdx])){
            maxIdx = i;
        }
    }
    return *invoices[maxIdx];
}


// Testing the program!!!
int main() {
    int test_case;
    char username[101];
    int userNumber;
    float basic_price;
    int spent_gigabytes;
    bool optical;
    int free_gigabytes;
    int num_inc;

    cin >> test_case;
    if (test_case == 1) {
        // Test Case Business Invoice - Constructor, operator <<
        cin >> username >> userNumber >> basic_price >> spent_gigabytes;
        cin >> optical >> free_gigabytes;
        BusinessInvoice bi(username, userNumber, basic_price, spent_gigabytes, optical, free_gigabytes);
        cout << "BusinessInvoice Created:\n";
        cout << bi;
    } else if (test_case == 2) {
        // Test Case Business Invoice - Constructor, operators <<, ++
        cin >> username >> userNumber >> basic_price >> spent_gigabytes;
        cin >> optical >> free_gigabytes;
        BusinessInvoice bi(username, userNumber, basic_price, spent_gigabytes, optical, free_gigabytes);
        cout << "BusinessInvoice:\n";
        cout << bi;
        cout << "testing operator++\n";

        // Additional spent gigabytes
        cin >> num_inc;
        for (int i = 0; i < num_inc; ++i) {
            bi++;
        }
        cout << bi;
    } else if (test_case == 3) {
        // Test Case Business Invoice - Constructor, total_price, operators <<, ++,
        cin >> username >> userNumber >> basic_price >> spent_gigabytes;
        cin >> optical >> free_gigabytes;
        BusinessInvoice bi(username, userNumber, basic_price, spent_gigabytes, optical, free_gigabytes);
        cout << "Testing total_price()\n";
        cout << bi;
        cout << bi.total_price() << endl;
        bi++;
        cout << bi;
        cout << bi.total_price() << endl;
    } else if (test_case == 4) {
        // Test Case Private Invoice - Constructor, operator <<
        cin >> username >> userNumber >> basic_price >> spent_gigabytes;

        PrivateInvoice pi(username, userNumber, basic_price, spent_gigabytes);
        cout << "Private Invoice Created:\n";
        cout << pi;
    } else if (test_case == 5) {
        // Test Case Private Invoice - Constructor, operators <<, ++
        cin >> username >> userNumber >> basic_price >> spent_gigabytes;
        PrivateInvoice pi(username, userNumber, basic_price, spent_gigabytes);
        cin >> num_inc;
        for (int i = 0; i < num_inc; ++i) {
            pi++;
        }
        cout << pi;
    } else if (test_case == 6) {
        // Test Case Private Invoice - Constructor, operators <<, +=
        cin >> username >> userNumber >> basic_price >> spent_gigabytes;
        PrivateInvoice pi(username, userNumber, basic_price, spent_gigabytes);
        cin >> num_inc;
        int film_length;
        for (int i = 0; i < num_inc; ++i) {
            cin >> film_length;
            pi += film_length;
        }
        cout << pi;
    } else if (test_case == 7) {
        // Test Case Private Invoice - Constructor, operators <<, +=, []
        cin >> username >> userNumber >> basic_price >> spent_gigabytes;
        PrivateInvoice pi(username, userNumber, basic_price, spent_gigabytes);
        cin >> num_inc;
        int film_length;
        for (int i = 0; i < num_inc; ++i) {
            cin >> film_length;
            pi += film_length;
        }
        cout << pi;
        cout << "Movie sizes: [";
        for (int i = 0; i < pi.getMoviesNo(); ++i) {
            cout << pi[i] << " ";
        }
        cout << "]" << endl;
    } else if (test_case == 8) {
        // Test Case Private Invoice - Constructor, total_price
        cin >> username >> userNumber >> basic_price >> spent_gigabytes;
        PrivateInvoice pi(username, userNumber, basic_price, spent_gigabytes);
        cout << pi;
        cout << pi.total_price() << endl;
        cin >> num_inc;
        int film_length;
        for (int i = 0; i < num_inc; ++i) {
            cin >> film_length;
            pi += film_length;
        }
        cin >> num_inc;
        for (int i = 0; i < num_inc; ++i) {
            pi++;
        }
        cout << pi;
        cout << pi.total_price() << endl;
    } else if (test_case == 9) {
        // Test Case

        int num_invoices;
        int invoice_type;

        cin >> num_invoices;
        MonthlyInvoice **mi = new MonthlyInvoice *[num_invoices];
        for (int j = 0; j < num_invoices; ++j) {

            cin >> invoice_type;
            if (invoice_type == 1) {
                cin >> username >> userNumber >> basic_price >> spent_gigabytes;
                cin >> optical >> free_gigabytes;
                BusinessInvoice *bip;
                bip = new BusinessInvoice(username, userNumber, basic_price, spent_gigabytes, optical, free_gigabytes);
                cin >> num_inc;
                for (int i = 0; i < num_inc; ++i) {
                    (*(bip))++;
                }
                cout << *(bip);
                cout << bip->total_price() << endl;

                mi[j] = bip;
            }
            if (invoice_type == 2) {
                cin >> username >> userNumber >> basic_price >> spent_gigabytes;
                PrivateInvoice *pip = new PrivateInvoice(username, userNumber, basic_price, spent_gigabytes);
                cin >> num_inc;
                int film_length;
                for (int i = 0; i < num_inc; ++i) {
                    cin >> film_length;
                    (*pip) += film_length;
                }
                cin >> num_inc;
                for (int i = 0; i < num_inc; ++i) {
                    (*pip)++;
                }
                cout << (*pip);
                cout << pip->total_price() << endl;
                mi[j] = pip;
            }
        }

        cout << "The biggest invoice is:\n";
        MonthlyInvoice &invoice = biggestInvoice(mi, num_invoices);

        MonthlyInvoice *m = &invoice;
        BusinessInvoice *bip;
        PrivateInvoice *pip;
        if (dynamic_cast<BusinessInvoice *> (m)) {
            bip = dynamic_cast<BusinessInvoice *> (m);
            cout << *bip << bip->total_price();
        }
        if (dynamic_cast<PrivateInvoice *> (m)) {
            pip = dynamic_cast<PrivateInvoice *> (m);
            cout << *pip << pip->total_price();
        }

    }
    return 0;
}