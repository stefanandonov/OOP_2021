#include <cstring>
#include <iostream>

using namespace std;


class MonthlyInvoice {
protected:
    char username[100];
    int phone;
    double basePrice;

public:
    MonthlyInvoice(char *name = "", int phone = 75111111, double basePrice = 0) : phone(phone), basePrice(basePrice) {
        strcpy(this->username, name);
    }

    MonthlyInvoice(const MonthlyInvoice &mi) {
        strcpy(this->username, mi.username);
        this->phone = mi.phone;
        this->basePrice = mi.basePrice;
    }

    virtual double total_price() const = 0;

    bool operator>(const MonthlyInvoice &mi) const {
        return total_price() > mi.total_price();
    }

};

class BusinessInvoice : public MonthlyInvoice {
private:
    char companyName[100];
    double gigabytes;
    int roamingMinutes;

public:
    BusinessInvoice(char *name = "", int phone = 75111111, double basePrice = 0,
                    char *companyName = "", int roamingMinutes = 0, double gigabytes = 0)
            : MonthlyInvoice(name, phone, basePrice) {
        strcpy(this->companyName, companyName);
        this->roamingMinutes = roamingMinutes;
        this->gigabytes = gigabytes;
    }

    BusinessInvoice(const BusinessInvoice &bi) : MonthlyInvoice(bi) {
        strcpy(this->companyName, bi.companyName);
        this->roamingMinutes = bi.roamingMinutes;
        this->gigabytes = bi.gigabytes;
    }

    double total_price() const override {
        return basePrice + gigabytes * 100 + roamingMinutes * 30;
    }

    friend ostream &operator<<(ostream &out, const BusinessInvoice &bi) {
        return out << bi.phone << " - " << bi.username << ", " << bi.basePrice << endl << bi.companyName << ", "
                   << bi.gigabytes << ", " << bi.roamingMinutes << endl;
    }

    BusinessInvoice operator++(int) {
        BusinessInvoice copy(*this);
        gigabytes += 1;
        return copy;
    }

    BusinessInvoice &operator+=(int roam) {
        this->roamingMinutes += roam;
        return *this;
    }

};

class PrivateInvoice : public MonthlyInvoice {
private:
    int smsMessages;
    int *durations;
    int nOfCalls;

    void copy(const PrivateInvoice &pi) {
        this->smsMessages = pi.smsMessages;
        durations = new int[pi.nOfCalls];
        nOfCalls = pi.nOfCalls;
//        strcpy(this->durations, pi.durations);//SO WRONG!!!!
        for (int i = 0; i < nOfCalls; i++)
            durations[i] = pi.durations[i];
    }

public:
    PrivateInvoice(char *name = "", int phone = 75111111, double basePrice = 0, int smsMessages = 0)
            : MonthlyInvoice(name, phone, basePrice) {
        this->smsMessages = smsMessages;
        durations = new int[0];
        nOfCalls = 0;
    }

    PrivateInvoice(const PrivateInvoice &pi) : MonthlyInvoice(pi) {
        copy(pi);
    }

    PrivateInvoice &operator=(const PrivateInvoice &pi) {
        if (this != &pi) {
            strcpy(this->username, pi.username);
            this->phone = pi.phone;
            this->basePrice = pi.basePrice;
            delete[] durations;
            copy(pi);
        }
        return *this;
    }

    ~PrivateInvoice() {
        delete[] durations;
    }

    int totalMinutes() const {
        int sum = 0;
        for (int i = 0; i < nOfCalls; i++) {
            sum += durations[i];
        }
        return sum;
    }

    double total_price() const override {
        return basePrice + smsMessages * 3 + totalMinutes() * 2.5;
    }

    friend ostream &operator<<(ostream &out, const PrivateInvoice &pi) {
        return out << pi.phone << " - " << pi.username << ", " << pi.basePrice << endl << pi.smsMessages << ", "
                   << pi.nOfCalls << ", " << pi.totalMinutes() << endl;
    }

    PrivateInvoice operator++(int) {
        PrivateInvoice copy(*this);
        ++smsMessages;
        return copy;
    }

    PrivateInvoice &operator+=(int newCallDuration) {
        int *tmp = new int[nOfCalls + 1];
        for (int i = 0; i < nOfCalls; i++) {
            tmp[i] = durations[i];
        }
        tmp[nOfCalls++] = newCallDuration;
        delete[] durations;
        durations = tmp;
        return *this;
    }

    int getTalksNo() {
        return nOfCalls;
    }

    int &operator[](int idx) {
        return durations[idx];
    }
};

MonthlyInvoice &biggestInvoice(MonthlyInvoice **invoices, int n) {
    MonthlyInvoice *max = invoices[0];
    for (int i = 1; i < n; i++) {
        if ((*invoices[i])>(*max)) { //pok kon MI, pok kon MI
            max = invoices[i];
        }
    }
    return *max;
}


//-- Test Code
int main() {
    int test_case;
    char username[101];
    int userNumber;
    int basic_price;
    char companyName[101];
    int spent_gigabytes;
    int roaming_minutes;
    int num_sms;
    int num_inc;

    cin >> test_case;
    if (test_case == 1) {
        // Test Case Business Invoice - Constructor, operator <<
        cin >> username >> userNumber >> basic_price;
        cin >> companyName >> spent_gigabytes >> roaming_minutes;
        BusinessInvoice bi(username, userNumber, basic_price, companyName,
                           roaming_minutes, spent_gigabytes);
        cout << "BusinessInvoice Created:\n";
        cout << bi;
    } else if (test_case == 2) {
        // Test Case Business Invoice - Constructor, operators <<, ++
        cin >> username >> userNumber >> basic_price;
        cin >> companyName >> spent_gigabytes >> roaming_minutes;
        BusinessInvoice bi(username, userNumber, basic_price, companyName,
                           roaming_minutes, spent_gigabytes);

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
        cin >> username >> userNumber >> basic_price;
        cin >> companyName >> spent_gigabytes >> roaming_minutes;
        BusinessInvoice bi(username, userNumber, basic_price, companyName,
                           roaming_minutes, spent_gigabytes);

        cout << "Testing total_price()\n";
        cout << bi;
        cout << bi.total_price() << endl;
        int x, roam;
        cin >> x; // GB
        for (int i = 0; i < x; ++i) {
            bi++;
        }
        cin >> roam; // roaming
        bi += roam;
        cout << bi;
        cout << bi.total_price() << endl;
    } else if (test_case == 4) {

        // Test Case Private Invoice - Constructor, operator <<
        cin >> username >> userNumber >> basic_price;
        cin >> num_sms;
        PrivateInvoice pi(username, userNumber, basic_price, num_sms);
        cout << "Private Invoice Created:\n";
        cout << pi;
    } else if (test_case == 5) {

        // Test Case Private Invoice - Constructor, operators <<, ++
        cin >> username >> userNumber >> basic_price;
        cin >> num_sms;
        PrivateInvoice pi(username, userNumber, basic_price, num_sms);

        cin >> num_sms;
        for (int i = 0; i < num_sms; ++i) {
            pi++;
        }
        cout << pi;
    } else if (test_case == 6) {
        // Test Case Private Invoice - Constructor, operators <<, +=
        cin >> username >> userNumber >> basic_price;
        cin >> num_sms;
        PrivateInvoice pi(username, userNumber, basic_price, num_sms);
        cin >> num_inc;
        int talk_length;
        for (int i = 0; i < num_inc; ++i) {
            cin >> talk_length;
            pi += talk_length;
        }
        cout << pi;
    } else if (test_case == 7) {
        // Test Case Private Invoice - Constructor, operators <<, +=, []
        cin >> username >> userNumber >> basic_price;
        cin >> num_sms;
        PrivateInvoice pi(username, userNumber, basic_price, num_sms);

        cin >> num_inc;
        int talk_length;
        for (int i = 0; i < num_inc; ++i) {
            cin >> talk_length;
            pi += talk_length;
        }
        cout << pi;
        cout << "Talks durations: [";
        for (int i = 0; i < pi.getTalksNo(); ++i) {
            cout << pi[i] << " ";
        }
        cout << "]" << endl;
    } else if (test_case == 8) {
        // Test Case Private Invoice - Constructor, total_price
        cin >> username >> userNumber >> basic_price;
        cin >> num_sms;
        PrivateInvoice pi(username, userNumber, basic_price, num_sms);

        cout << pi;
        cout << pi.total_price() << endl;
        cin >> num_inc;
        int talk_length;
        for (int i = 0; i < num_inc; ++i) {
            cin >> talk_length;
            pi += talk_length;
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
                cin >> username >> userNumber >> basic_price;
                cin >> companyName;
                cin >> roaming_minutes >> spent_gigabytes;
                BusinessInvoice bi(username, userNumber, basic_price, companyName,
                                   roaming_minutes, spent_gigabytes);

                BusinessInvoice *bip;
                bip =
                        new BusinessInvoice(username, userNumber, basic_price, companyName,
                                            roaming_minutes, spent_gigabytes);

                cin >> num_inc;
                for (int i = 0; i < num_inc; ++i) {
                    (*(bip))++;
                }
                cin >> num_inc;
                (*(bip) += num_inc);

                cout << *(bip);
                cout << bip->total_price() << endl;

                mi[j] = bip;
            }
            if (invoice_type == 2) {
                cin >> username >> userNumber >> basic_price >> num_sms;
                PrivateInvoice *pip =
                        new PrivateInvoice(username, userNumber, basic_price, num_sms);
                cin >> num_inc;
                int talk_length;
                for (int i = 0; i < num_inc; ++i) {
                    cin >> talk_length;
                    (*pip) += talk_length;
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
        if (dynamic_cast<BusinessInvoice *>(m)) {
            bip = dynamic_cast<BusinessInvoice *>(m);
            cout << *bip << bip->total_price();
        }
        if (dynamic_cast<PrivateInvoice *>(m)) {
            pip = dynamic_cast<PrivateInvoice *>(m);
            cout << *pip << pip->total_price();
        }
    }
    return 0;
}