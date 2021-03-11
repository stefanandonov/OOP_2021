//
// Created by Stefan Andonov on 3/11/21.
//

#include<iostream>

using namespace std;

class EmailMessage {
private:
    char sender[50];
    char receiver[50];
    char subject[50];
    char body[500];
public:
    EmailMessage(char *_sender = "info@finki.ukim.mk",
                 char *_receiver = "random_student@students.finki.ukim.mk",
                 char *_subject = "Apply for internship",
                 char *_body = "Dear student, Please find attached the call for interns in the company XY. \nBest regards, FINKI") {
        strcpy(sender, _sender);
        strcpy(receiver, _receiver);
        strcpy(subject, _subject);
        strcpy(body, _body);
    }

    void show() {
        cout << "Sender:   \t" << sender << endl;
        cout << "Receiver: \t" << receiver << endl;
        cout << "-------------------------------------------------------------------------" << endl;
        cout << "Subject:  \t" << subject << endl;
        cout << "-------------------------------------------------------------------------" << endl;
        cout << body << endl;
        cout << "ENDS" << endl;
    }
};

bool valid(char *email) {
    char *ptr = strchr(email, '@'); //stefan@finki.ukim.mk --> @finki.ukim.mk ; stefanfinki -> NULL pointer
    if (ptr != nullptr) {
        return strchr(ptr, '.') != nullptr;
    } else return false;

//    int idx = -1, i=0;
//    while (*email!='\0') {
//        if (*email=='@') {
//            idx = i;
//            break;
//        }
//        email++;
//        ++i;
//    }
//
//    if (idx==-1) {
//        return false;
//    } else {
//        while(*email!='\0') {
//            if (*email=='.')
//                return true;
//        }
//        return false;
//    }
}

int main() {
//    EmailMessage m;
//    m.show();
    char sender[50], receiver[50], subject[50], body[500];
    cin.getline(sender, 50);
    cin.getline(receiver, 50);
    if (valid(sender) && valid(receiver)) {
        cin.getline(subject, 50);
        cin.getline(body, 500);
        EmailMessage message(sender, receiver, subject, body);
        message.show();
    } else {
        cout<<"Invalid emails!"<<endl;
    }
    return 0;
}