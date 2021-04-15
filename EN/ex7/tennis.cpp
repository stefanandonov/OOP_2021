//
// Created by Stefan Andonov on 4/15/21.
//

#include<iostream>

using namespace std;

class TennisPlayer {
protected:
    char firstName[50];
    char lastName[50];
    bool playsInLeague;
public:
    TennisPlayer(char *firstName = "", char *lastName = "", bool playsInLeague = false) {
        cout<<"TennisPlayer constructor called!"<<endl;
        strcpy(this->firstName, firstName);
        strcpy(this->lastName, lastName);
        this->playsInLeague = playsInLeague;
    }

    TennisPlayer(const TennisPlayer &tp) {
        cout<<"TennisPlayer copy-constructor called!"<<endl;
        strcpy(this->firstName, tp.firstName);
        strcpy(this->lastName, tp.lastName);
        this->playsInLeague = tp.playsInLeague;
    }

    friend ostream &operator<<(ostream &out, const TennisPlayer &tp) {
        return out << tp.firstName << " " << tp.lastName << " " << (tp.playsInLeague ? "YES" : "NO");
    }

    ~TennisPlayer() {
        cout<<"TennisPlayer destructor called!"<<endl;
    }
};

class RankedTennisPlayer : public TennisPlayer {
private:
    int rank;
public:
    RankedTennisPlayer(char *firstName = "", char *lastName = "", int rank = 1000)
            : TennisPlayer(firstName, lastName, true) {
        cout<<"RankedTennisPlayer constructor called!"<<endl;
        this->rank = rank;
    }

    RankedTennisPlayer(const TennisPlayer & tp, int rank) : TennisPlayer(tp) {
        this->rank = rank;
    }

    RankedTennisPlayer(const RankedTennisPlayer &rtp) : TennisPlayer(rtp) {
        cout<<"RankedTennisPlayer copy-constructor called!"<<endl;
        this->rank = rtp.rank;
    }

    friend ostream &operator<<(ostream &out, const RankedTennisPlayer &rtp) { //Rafael Nadal YES 2
        TennisPlayer tp (rtp);
        return out <<tp<<" Rank: "<< rtp.rank;
    }

    ~RankedTennisPlayer() {
        cout<<"RankedTennisPlayer destructor called!"<<endl;
    }
};

int main() {
//    TennisPlayer tp("Rafael", "Nadal", true);
//    cout << tp << endl;
    RankedTennisPlayer rtp("Rafael", "Nadal", 2);
//    RankedTennisPlayer rtp (tp, 2);
//    cout << rtp << endl;
    return 0;
}