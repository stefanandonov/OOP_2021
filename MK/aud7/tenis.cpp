//
// Created by Stefan Andonov on 4/21/21.
//

#include<iostream>
using namespace std;

class TennisPlayer {
protected:
    char * firstName;
    char * lastName;
    bool playsInLeague;

    void copy (const TennisPlayer & tp) {
        this->firstName = new char [strlen(tp.firstName)+1];
        this->lastName = new char [strlen(tp.lastName)+1];
        strcpy(this->firstName, tp.firstName);
        strcpy(this->lastName, tp.lastName);
        this->playsInLeague = tp.playsInLeague;
    }

    void deleteDynamicallyAllocated () {
        delete [] firstName;
        delete [] lastName;
    }
public:
    TennisPlayer(char * firstName = "", char * lastName = "", bool playsInLeague = false) {
        this->firstName = new char [strlen(firstName)+1];
        this->lastName = new char [strlen(lastName)+1];
        strcpy(this->firstName, firstName);
        strcpy(this->lastName, lastName);
        this->playsInLeague = playsInLeague;
    }

    TennisPlayer (const TennisPlayer & tp) {
        copy(tp);
    }

    TennisPlayer & operator = (const TennisPlayer & tp) {
        if (this!=&tp) {
            deleteDynamicallyAllocated();
            copy(tp);
        }
        return *this;
    }

    ~TennisPlayer() {
        deleteDynamicallyAllocated();
    }

    friend ostream & operator << (ostream & out, const TennisPlayer &tp) {
        return out<<tp.firstName<<" "<<tp.lastName<<" "<<(tp.playsInLeague ? "YES" : "NO");
    }
};

class RankedTennisPlayer : public TennisPlayer {
private:
    int rank;

    void copy (const RankedTennisPlayer & rtp) {
        TennisPlayer::copy(rtp);
        this->rank = rtp.rank;
    }
public:
    RankedTennisPlayer(char * firstName = "", char * lastName = "", int rank = 1000) : TennisPlayer(firstName, lastName, true) {
        this->rank = rank;
    }

    RankedTennisPlayer (TennisPlayer & tp, int rank = 1000) : TennisPlayer(tp) {
        this->rank = rank;
        this->playsInLeague=true;
    }

    RankedTennisPlayer (const RankedTennisPlayer & rtp)  {
        copy(rtp);
    }

    RankedTennisPlayer & operator = (const RankedTennisPlayer & rtp) {
//        TennisPlayer::operator=(rtp);
//        this->rank = rtp.rank;
//        return *this;
        if (this!=&rtp) {
            TennisPlayer::deleteDynamicallyAllocated();
            copy(rtp);
        }
        return *this;
    }

//    ~RankedTennisPlayer() {
//        TennisPlayer::deleteDynamicallyAllocated();
//    }

    friend ostream & operator << (ostream & out, const RankedTennisPlayer & rtp) {
        TennisPlayer tp (rtp);
        return out<<tp<<" "<<rtp.rank; //firstName, lastName, playsInLeague
    }
};

int main () {
    TennisPlayer tp ("Rafael", "Nadal", true);
    cout<<tp<<endl;
    RankedTennisPlayer rtp (tp, 2);
    cout<<rtp<<endl;

    RankedTennisPlayer rtp2;
    rtp2 = rtp;
    cout<<rtp2<<endl;

    return 0;
}