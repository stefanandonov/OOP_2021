//
// Created by Stefan Andonov on 5/12/21.
//

#include<string.h>
#include<iostream>

using namespace std;

class InvalidRatingException {
public:
    void showMessage() {
        cout<<"Ocenata za parkot ne e validna"<<endl;
    }
};

class LunaPark {
protected:
    char address[40];
    int year;
    int month;
    float minimumTime;
    int attractions;

public:
    LunaPark(char *name = "", int year = 1990, int month = 1, float time = 0, int attractions = 0) : year(year),
                                                                                                     month(month),
                                                                                                     minimumTime(time),
                                                                                                     attractions(
                                                                                                             attractions) {
        strcpy(this->address, name);
    }

    LunaPark(const LunaPark &lp) : year(lp.year), month(lp.month), minimumTime(lp.minimumTime),
                                   attractions(lp.attractions) {
        strcpy(address, lp.address);
    }

    virtual double rating() const {
        return minimumTime * attractions;
    }

    friend ostream &operator<<(ostream &out, const LunaPark &lp) {
        return out << lp.address << " " << lp.month << "." << lp.year << " " << lp.rating() << endl;
    }
};

class AdventurePark : public LunaPark {
private:
    float *ratings;
    int nOfRatings;
    int maxVisitors;

    void copy(const AdventurePark &ap) {
        this->maxVisitors = ap.maxVisitors;
        this->nOfRatings = ap.nOfRatings;
        ratings = new float[nOfRatings];
        for (int i = 0; i < nOfRatings; i++)
            ratings[i] = ap.ratings[i];
    }

public:
    static const double COEF;

    AdventurePark(char *address = "", int year = 1990, int month = 1, float time = 10,
                  int numAttractions = 0, float *grades = new float [0], int n = 0, int maxVisitors = 0)
            : LunaPark(address, year, month, time, numAttractions) {
        nOfRatings = n;
        ratings = new float[nOfRatings];
        for (int i = 0; i < nOfRatings; i++) {
            ratings[i] = grades[i];
        }
        this->maxVisitors = maxVisitors;
    }

    AdventurePark(const AdventurePark &ap) : LunaPark(ap) {
        copy(ap);
    }

    AdventurePark &operator=(const AdventurePark &ap) {
        if (this != &ap) {
            strcpy(this->address, ap.address);
            this->month = ap.month;
            this->year = ap.year;
            this->minimumTime = ap.minimumTime;
            this->attractions = ap.attractions;
            delete[] ratings;
            copy(ap);
        }
        return *this;
    }

    ~AdventurePark() {
        delete[] ratings;
    }

    double averageGrade() const {
        double sum = 0;
        for (int i = 0; i < nOfRatings; i++) {
            sum += ratings[i];
        }
        return sum / nOfRatings;
    }

    double rating() const override {
        double r = LunaPark::rating() + averageGrade() * COEF;
        if (maxVisitors < 500)
            r *= 0.85;
        return r;
    }

    AdventurePark & operator += (double grade) {
        if (grade<0 || grade>10) {
            throw InvalidRatingException();
        }
        float * tmp = new float [nOfRatings+1];
        for (int i=0;i<nOfRatings;i++)
            tmp[i]=ratings[i];
        tmp[nOfRatings]=grade;
        nOfRatings++;
        delete [] ratings;
        ratings = tmp;
        return *this;
    }

    AdventurePark & operator ++ () {
        ++maxVisitors;
        return *this;
    }

    void setnumberGrades(int i);

    int getnumberGrades() {
        return maxVisitors;
    }

    static double getKoeficient () {
        return COEF;
    }
};

const double AdventurePark::COEF = 0.5;

void AdventurePark::setnumberGrades(int i) {
    this->nOfRatings = i;

}

int main() {
    int testCase;
    cin >> testCase;
    char address[50];
    int year;
    int month;
    float time;
    float numAttractions;
    float grades[50];
    int n;
    int m;
    int izbor;
    int numberGrades;

    if (testCase == 1) {
        cout << "===== Testiranje na klasite ======" << endl;
        cin >> address;
        cin >> year;
        cin >> month;
        cin >> time;
        cin >> numAttractions;
        LunaPark t(address, year, month, time, numAttractions);
        cout << t;
        cin >> address;
        cin >> year;
        cin >> month;
        cin >> time;
        cin >> numAttractions;
        cin >> numberGrades;
        cin >> n;
        for (int j = 0; j < n; j++)
            cin >> grades[j];
        AdventurePark adv(address, year, month, time, numAttractions, grades, n, numberGrades);
        cout << adv;
        AdventurePark adv2;
    }
    if (testCase == 2) {
        cout << "===== Testiranje na operatorot += ======" << endl;
        LunaPark **niza;
        cin >> m;
        niza = new LunaPark *[m];
        for (int i = 0; i < m; i++) {
            cin >> izbor;
            cin >> address;
            cin >> year;
            cin >> month;
            cin >> time;
            cin >> numAttractions;
            if (izbor == 1) {
                niza[i] = new LunaPark(address, year, month, time, numAttractions);
            } else {
                cin >> numberGrades;
                cin >> n;
                for (int j = 0; j < n; j++)
                    cin >> grades[j];
                niza[i] = new AdventurePark(address, year, month, time, numAttractions, grades, n, numberGrades);
            }
        }
        // pecatenje na site Luna parkovi
        cout << "\nLista na site Luna parkovi:\n";
        for (int i = 0; i < m; i++)
            cout << *niza[i];

        // dodavanje novo najdobro vreme za prvata AdventurePark
        float best;
        cin >> best;
        int flag = 1;
        for (int i = 0; i < m; i++) {
            AdventurePark *nn = dynamic_cast<AdventurePark *>(niza[i]);
            if (nn != 0) {
                flag = 0;
                (*nn) += best;
                break;
            }
        }


        // pecatenje na site Luna parkovi
        cout << "\nLista na site Luna parkovi:\n";
        for (int i = 0; i < m; i++)
            cout << *niza[i];
    }
    if (testCase == 3) {
        cout << "===== Testiranje na isklucoci ======" << endl;
        cin >> address;
        cin >> year;
        cin >> month;
        cin >> time;
        cin >> numAttractions;
        cin >> numberGrades;
        AdventurePark adv(address, year, month, time, numAttractions);
//        adv.setnumberGrades(numberGrades);
        float vreme1, vreme2;
        cin >> vreme1 >> vreme2;

        adv += vreme1;
        adv += vreme2;

        cout << adv;
    }
    if (testCase == 4) {
        cout << "===== Testiranje na operator++ ======" << endl;
        cin >> address;
        cin >> year;
        cin >> month;
        cin >> time;
        cin >> numAttractions;
        cin >> numberGrades;
        cin >> n;
        for (int j = 0; j < n; j++)
            cin >> grades[j];


        AdventurePark adv(address, year, month, time, numAttractions, grades, n, numberGrades);
        float v, koef2;
        cout << adv;
        cout << (++adv).getnumberGrades() << endl;
        ++adv;
        cout << adv;
    }
    if (testCase == 5) {
        cout << "===== Testiranje na static clenovi ======" << endl;
        LunaPark **niza;
        cin >> m;
        niza = new LunaPark *[m];
        for (int i = 0; i < m; i++) {
            cin >> izbor;
            cin >> address;
            cin >> year;
            cin >> month;
            cin >> time;
            cin >> numAttractions;
            if (izbor == 1) {
                niza[i] = new LunaPark(address, year, month, time, numAttractions);
            } else {
                cin >> numberGrades;
                cin >> n;
                for (int j = 0; j < n; j++)
                    cin >> grades[j];
                niza[i] = new AdventurePark(address, year, month, time, numAttractions, grades, n, numberGrades);
            }
        }
        // pecatenje na site Luna parkovi
        cout << "\nLista na site Luna parkovi:\n";
        for (int i = 0; i < m; i++)
            cout << *niza[i];

        cout << "Koeficientot e: " << AdventurePark::getKoeficient() << endl;
    }

    if (testCase == 6) {
        cout << "===== Testiranje na kompletna funkcionalnost ======" << endl;
        LunaPark **niza;
        cin >> m;
        niza = new LunaPark *[m];
        for (int i = 0; i < m; i++) {
            cin >> izbor;
            cin >> address;
            cin >> year;
            cin >> month;
            cin >> time;
            cin >> numAttractions;
            if (izbor == 1) {
                niza[i] = new LunaPark(address, year, month, time, numAttractions);
            } else {
                cin >> numberGrades;
                cin >> n;
                for (int j = 0; j < n; j++)
                    cin >> grades[j];
                niza[i] = new AdventurePark(address, year, month, time, numAttractions, grades, n, numberGrades);
            }
        }
        // pecatenje na site Luna parkovi
        cout << "\nLista na site Luna parkovi:\n";
        for (int i = 0; i < m; i++)
            cout << *niza[i];
        // pecatenje na site Luna parkovi
        float newSc;
        cin >> newSc;
        int flag = 1;
        for (int i = 0; i < m; i++) {
            AdventurePark *pok = dynamic_cast<AdventurePark *>(niza[i]);
            if (pok != 0) {
                ++(*pok);

                try {
                    (*pok) += newSc;
                    if (flag == 1) {
                        flag = 0;
                        *pok += 16.4;


                    }
                }
                catch (InvalidRatingException & e) {
                    e.showMessage();
                }
            }
        }
        cout << "\nLista na site Luna parkovi:\n";
        for (int i = 0; i < m; i++)
            cout << *niza[i];
    }

    return 0;
}