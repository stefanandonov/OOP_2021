#include<iostream>
#include<string.h>

using namespace std;

class InvalidTimeException {
public:
    void showMessage() {
        cout << "Invalid Time" << endl;
    }
};

class Race {
protected:
    char city[40];
    int year;
    int month;
    float bestTime;
    float length;

    void copy(const Race &r) {
        strcpy(this->city, r.city);
        this->year = r.year;
        this->month = r.month;
        this->bestTime = r.bestTime;
        this->length = r.length;
    }

public:
    Race(char *city = "", int year = 2000, int month = 1, float bestTime = 1, float length = 10) {
        strcpy(this->city, city);
        this->year = year;
        this->month = month;
        this->bestTime = bestTime;
        this->length = length;
    }

    Race(const Race &r) {
        copy(r);
    }

    Race &operator=(const Race &r) {
        if (this != &r) {
            copy(r);
        }
        return *this;
    }

    virtual float complexity() const {
        return bestTime / length;
    }

    friend ostream &operator<<(ostream &out, const Race &r) {
        return out << r.city << " " << r.month << "." << r.year << " " << r.complexity() << endl;
    }
};

class MotoGPRace : public Race {
private:
    float *bestTimesOfPreparation;
    int n;
    int laps;

    void copy(const MotoGPRace &mgpr) {
        Race::copy(mgpr);
        this->n = mgpr.n;
        bestTimesOfPreparation = new float[this->n];
        for (int i = 0; i < n; i++) {
            this->bestTimesOfPreparation[i] = mgpr.bestTimesOfPreparation[i];
        }
        this->laps = mgpr.laps;
    }

public:
    static float MOTO_GP_COEFFICIENT;

    MotoGPRace () : Race() {
        laps = 0;
        bestTimesOfPreparation = new float [0];
        n = 0;
    }
    MotoGPRace(char *city, int year, int month , float bestTime ,
               float length , float *bestTimesOfPreparation ,
               int n, int laps) : Race(city, year, month, bestTime, length) {
        this->n = n;
        this->bestTimesOfPreparation = new float[this->n];
        for (int i = 0; i < n; i++) {
            this->bestTimesOfPreparation[i] = bestTimesOfPreparation[i];
        }
        this->laps = laps;
    }

    MotoGPRace(char *city, int year, int month , float bestTime ,
               float length) : Race(city, year, month, bestTime, length) {
        laps = 0;
        bestTimesOfPreparation = new float [0];
        n = 0;
    }

    MotoGPRace(const MotoGPRace &motoGpRace) {
        copy(motoGpRace);
    }

    MotoGPRace &operator=(const MotoGPRace &motoGpRace) {
        if (this != &motoGpRace) {
            delete [] bestTimesOfPreparation;
            copy(motoGpRace);
        }
        return *this;
    }

    ~MotoGPRace() {
        delete[] bestTimesOfPreparation;
    }

    float averageBestTimeOfPreparation() const {
        float sum = 0;
        for (int i = 0; i < n; i++)
            sum += bestTimesOfPreparation[i];
        return sum / n;
    }

    float complexity() const {
        float c = Race::complexity() + (averageBestTimeOfPreparation() * MOTO_GP_COEFFICIENT);
        if (laps > 22)
            return c * 1.2;
        else
            return c;
    }

    MotoGPRace &operator+=(float time) {
        if (time < 9.5) {
            throw InvalidTimeException();
        }
        float *tmp = new float[n + 1];
        for (int i = 0; i < n; i++) {
            tmp[i] = bestTimesOfPreparation[i];
        }
        tmp[n++] = time;
        delete[] bestTimesOfPreparation;
        bestTimesOfPreparation = tmp;
        return *this;
    }

    MotoGPRace operator ++ (int) {
        MotoGPRace copy (*this);
        laps++;
        return copy;
    }

    void setNumberLaps(int i) {
        laps = i;
    }

    int getNumberLaps () {
        return laps;
    }

    static void setK(double d);
};

float MotoGPRace::MOTO_GP_COEFFICIENT = 0.4;

void MotoGPRace::setK(double d) {
    MOTO_GP_COEFFICIENT = d;
}

int main() {
    int testCase;
    cin >> testCase;
    char city[50];
    int year;
    int month;
    float bestTime;
    float length;
    float bestTimes[50];
    int n;
    int m;
    int choice;
    int numberLaps;

    if (testCase == 1) {
        cout << "===== Testing - classes ======" << endl;
        cin >> city;
        cin >> year;
        cin >> month;
        cin >> bestTime;
        cin >> length;
        Race t(city, year, month, bestTime, length);
        cout << t;
        cin >> city;
        cin >> year;
        cin >> month;
        cin >> bestTime;
        cin >> length;
        cin >> numberLaps;
        cin >> n;
        for (int j = 0; j < n; j++)
            cin >> bestTimes[j];
        MotoGPRace mgt(city, year, month, bestTime, length, bestTimes, n, numberLaps);
        cout << mgt;
        MotoGPRace mgt2;
    }
    if (testCase == 2) {
        cout << "===== Testing - operatorot += ======" << endl;
        Race **rArray;
        cin >> m;
        rArray = new Race *[m];
        for (int i = 0; i < m; i++) {
            cin >> choice;
            cin >> city;
            cin >> year;
            cin >> month;
            cin >> bestTime;
            cin >> length;
            if (choice == 1) {
                rArray[i] = new Race(city, year, month, bestTime, length);
            } else {
                cin >> numberLaps;
                cin >> n;
                for (int j = 0; j < n; j++)
                    cin >> bestTimes[j];
                rArray[i] = new MotoGPRace(city, year, month, bestTime, length, bestTimes, n, numberLaps);
            }
        }
        // print the races
        cout << "\nList of all races:\n";
        for (int i = 0; i < m; i++)
            cout << *rArray[i];

        // add a new best time
        float best;
        cin >> best;
        int flag = 1;
        for (int i = 0; i < m; i++) {
            MotoGPRace *nn = dynamic_cast<MotoGPRace *>(rArray[i]);
            if (nn != 0) {
                flag = 0;
                (*nn) += best;
                break;
            }
        }

        // print the races
        cout << "\nLista na site Trki:\n";
        for (int i = 0; i < m; i++)
            cout << *rArray[i];
    }
    if (testCase == 3) {
        cout << "===== Testing - exceptions ======" << endl;
        cin >> city;
        cin >> year;
        cin >> month;
        cin >> bestTime;
        cin >> length;
        cin >> numberLaps;
        MotoGPRace mgt(city, year, month, bestTime, length);
        mgt.setNumberLaps(numberLaps);
        float time1, time2;
        cin >> time1 >> time2;

        try {
            mgt += time1;
            mgt += time2;
        } catch (InvalidTimeException & e) {
            e.showMessage();
        }

        cout << mgt;
    }
    if (testCase == 4) {
        cout << "===== Testing - operator++ ======" << endl;
        cin >> city;
        cin >> year;
        cin >> month;
        cin >> bestTime;
        cin >> length;
        cin >> numberLaps;
        cin >> n;
        for (int j = 0; j < n; j++)
            cin >> bestTimes[j];

        MotoGPRace mgt(city, year, month, bestTime, length, bestTimes, n, numberLaps);
        float v, koef2;
        cout << (mgt++).getNumberLaps() << endl;
        cout << mgt;
        mgt++;
        cout << mgt;
    }
    if (testCase == 5) {
        cout << "===== Testing - coefficient ======" << endl;
        Race **rArray;
        cin >> m;
        rArray = new Race *[m];
        for (int i = 0; i < m; i++) {
            cin >> choice;
            cin >> city;
            cin >> year;
            cin >> month;
            cin >> bestTime;
            cin >> length;
            if (choice == 1) {
                rArray[i] = new Race(city, year, month, bestTime, length);
            } else {
                cin >> numberLaps;
                cin >> n;
                for (int j = 0; j < n; j++)
                    cin >> bestTimes[j];
                rArray[i] = new MotoGPRace(city, year, month, bestTime, length, bestTimes, n, numberLaps);
            }
        }
        // print the races
        cout << "\nList of all races:\n";
        for (int i = 0; i < m; i++)
            cout << *rArray[i];

        MotoGPRace::setK(0.7);
        // print the races
        cout << "\nList of all races:\n";
        for (int i = 0; i < m; i++)
            cout << *rArray[i];
    }

    if (testCase == 6) {
        cout << "===== Testing - full functionality ======" << endl;
        Race **rArray;
        cin >> m;
        rArray = new Race *[m];
        for (int i = 0; i < m; i++) {
            cin >> choice;
            cin >> city;
            cin >> year;
            cin >> month;
            cin >> bestTime;
            cin >> length;
            if (choice == 1) {
                rArray[i] = new Race(city, year, month, bestTime, length);
            } else {
                cin >> numberLaps;
                cin >> n;
                for (int j = 0; j < n; j++)
                    cin >> bestTimes[j];
                rArray[i] = new MotoGPRace(city, year, month, bestTime, length, bestTimes, n, numberLaps);
            }
        }
        // print the races
        cout << "\nList of all races:\n";
        for (int i = 0; i < m; i++)
            cout << *rArray[i];
        float newCoef;
        cin >> newCoef;
        MotoGPRace::setK(newCoef);
        cout << "\nList of all races:\n";
        for (int i = 0; i < m; i++)
            cout << *rArray[i];
        // print the races
        float newBest;
        cin >> newBest;
        int flag = 1;
        for (int i = 0; i < m; i++) {
            try {
                MotoGPRace *pok = dynamic_cast<MotoGPRace *>(rArray[i]);
                if (pok != 0) {
                    (*pok)++;
                    (*pok) += newBest;
                    if (flag == 1) {
                        flag = 0;
                        *pok += 1.4;

                    }
                }
            } catch (InvalidTimeException & e) {
                e.showMessage();
            }
        }
        cout << "\nList of the races:\n";
        for (int i = 0; i < m; i++)
            cout << *rArray[i];
    }

    return 0;
}
