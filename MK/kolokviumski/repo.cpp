#include<iostream>
#include<cstring>

using namespace std;

enum Tip {
    LINUX, UNIX, WINDOWS
};

class OperativenSistem {
    char *ime;
    float verzija;
    Tip tip;
    float golemina;

    void copy(const OperativenSistem &other) {
        this->ime = new char[strlen(other.ime) + 1];
        strcpy(this->ime, other.ime);
        this->verzija = other.verzija;
        this->tip = other.tip;
        this->golemina = other.golemina;
    }

public:
    OperativenSistem(char *ime = "", float verzija = 1.0, Tip tip = LINUX, float golemina = 2.4) {
        this->ime = new char[strlen(ime) + 1];
        strcpy(this->ime, ime);
        this->verzija = verzija;
        this->tip = tip;
        this->golemina = golemina;
    }

    OperativenSistem(const OperativenSistem &os) {
        copy(os);
    }

    OperativenSistem &operator=(const OperativenSistem &os) {
        if (this != &os) {
            delete[] ime;
            copy(os);
        }
        return *this;
    }

    ~OperativenSistem() {
        delete[] ime;
    }

    //Ime: Ubuntu Verzija: 16.04 Tip: 1 Golemina:1.25GB
    friend ostream &operator<<(ostream &out, const OperativenSistem &os) {
        return out << "Ime: " << os.ime << " Verzija: " << os.verzija << " Tip: " << os.tip << " Golemina:"
                   << os.golemina << "GB" << endl;
    }

    bool operator==(const OperativenSistem &os) {
        return strcmp(this->ime, os.ime) == 0 && this->verzija == os.verzija &&
               this->tip == os.tip && this->golemina == golemina;
    }

    bool operator!=(const OperativenSistem &os) {
        return !((*this) == os);
    }

    bool operator>(const OperativenSistem &os) {
        return this->verzija > os.verzija;
    }

    bool istaFamilija(const OperativenSistem &os) {
        return strcmp(this->ime, os.ime) == 0 && this->tip == os.tip;
    }

    OperativenSistem operator+(const OperativenSistem &os) {
        return OperativenSistem(this->ime,
                                (this->verzija > os.verzija) ? this->verzija : os.verzija,
                                this->tip,
                                this->golemina + os.golemina);
    }
};

class Repozitorium {
    char ime[20];
    OperativenSistem *operativniSistemi;
    int n;

    void copy(const Repozitorium &r) {
        strcpy(this->ime, r.ime);
        operativniSistemi = new OperativenSistem[r.n];
        this->n = r.n;
        for (int i = 0; i < n; i++) {
            operativniSistemi[i] = r.operativniSistemi[i];
        }
    }

public:
    Repozitorium(char *ime = "") {
        strcpy(this->ime, ime);
        operativniSistemi = new OperativenSistem[0];
        n = 0;
    }

    Repozitorium(const Repozitorium &r) {
        copy(r);
    }

    Repozitorium &operator=(const Repozitorium &r) {
        if (this != &r) {
            delete[] operativniSistemi;
            copy(r);
        }
        return *this;
    }

    ~Repozitorium() {
        delete[] operativniSistemi;
    }

    friend ostream &operator<<(ostream &out, const Repozitorium &r) {
        out << "Repozitorium: " << r.ime << endl;
        for (int i = 0; i < r.n; i++) {
            out << r.operativniSistemi[i];
        }
        return out;
    }

    Repozitorium &operator+=(OperativenSistem &os) {
        for (int i = 0; i < n; i++) {
            if (operativniSistemi[i].istaFamilija(os)) {
                if (os > operativniSistemi[i]) {
                    operativniSistemi[i] = os;
                    return *this;
                }
            }
        }

        OperativenSistem *tmp = new OperativenSistem[n + 1];
        for (int i = 0; i < n; i++)
            tmp[i] = operativniSistemi[i];
        tmp[n++] = os;
        delete[] operativniSistemi;
        operativniSistemi = tmp;
        return *this;
    }

    bool contains(const OperativenSistem &os) {
        for (int i = 0; i < n; i++) {
            if (operativniSistemi[i] == os)
                return true;
        }
        return false;
    }

    Repozitorium &operator-=(const OperativenSistem &os) {
        if (contains(os)) {
            OperativenSistem *tmp = new OperativenSistem[n - 1];
            for (int i = 0, j = 0; i < n; i++) {
                if (operativniSistemi[i] != os) {
                    tmp[j++] = operativniSistemi[i];
                }
            }
            --n;
            delete[] operativniSistemi;
            operativniSistemi = tmp;
        }
        return *this;
    }

    OperativenSistem &operator[](int idx) {
        return operativniSistemi[idx];
    }

    int getBrojNaOS() {
        return n;
    }
};

int main() {
    char repoName[20];
    cin >> repoName;
    Repozitorium repozitorium = Repozitorium(repoName);
    int brojOperativniSistemi = 0;
    cin >> brojOperativniSistemi;
    char ime[20];
    float verzija;
    int tip;
    float golemina;
    for (int i = 0; i < brojOperativniSistemi; i++) {
        cin >> ime;
        cin >> verzija;
        cin >> tip;
        cin >> golemina;
        OperativenSistem os = OperativenSistem(ime, verzija, (Tip) tip, golemina);
        repozitorium += os;
    }

    for (int i = 0; i < repozitorium.getBrojNaOS(); i++) {
        for (int j = 0; j < repozitorium.getBrojNaOS(); j++) {
            if (i != j && repozitorium[i].istaFamilija(repozitorium[j])) {
                cout << repozitorium[i] + repozitorium[j];
            }
        }
    }

    cout << repozitorium;
    cin >> ime;
    cin >> verzija;
    cin >> tip;
    cin >> golemina;
    OperativenSistem os = OperativenSistem(ime, verzija, (Tip) tip, golemina);
    cout << "=====Brishenje na operativen sistem=====" << endl;
    repozitorium -= os;
    cout << repozitorium;


    return 0;
}