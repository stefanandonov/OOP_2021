//
// Created by Stefan Andonov on 3/10/21.
//

#include<iostream>
#include<cstring>

using namespace std;

bool valid(char sender[50]);

class EmailNotValidException {
    char email[50];
public:
    EmailNotValidException(char * email){
        strcpy(this->email, email);
    }

    void printMessage() {
        cout<<"Email "<<email<<" is not valid!"<<endl;
    }
};

class EmailMessage {
private:
    char sender[50];
    char receiver[50];
    char subject[50];
    char body[300];
public:
    EmailMessage(char *_sender = "info@finki.ukim.mk",
                 char *_receiver = "stefan@students.finki.ukim.mk",
                 char *_subject = "Disciplinska kazna",
                 char *_body = "Kaznet si! Koj saka neka cestita!") {
        if (!valid(_sender)) {
            throw EmailNotValidException(_sender);
        }

        if (!valid(_receiver)) {
            throw EmailNotValidException(_receiver);
        }
        strcpy(sender, _sender);
        strcpy(receiver, _receiver);
        strcpy(subject, _subject);
        strcpy(body, _body);
    }

    void show() {
        cout << "From   :\t" << sender << endl;
        cout << "To     :\t" << receiver << endl;
        cout << "----------------------------------------------" << endl;
        cout << "Subject:\t" << subject << endl;
        cout << "----------------------------------------------" << endl;
        cout << "Body: " << endl;
        cout << body << endl;
        cout << "ENDS";
    }
};



int main() {
    char sender[50];
    char receiver[50];
    char subject[50];
    char body[300];
    cin.getline(sender, 50);
    cin.getline(receiver, 50);
//    if (!valid(sender) || !valid(receiver)) {
////        cout << "sender or receiver has an invalid email address" << endl;
//        return 0;
//    }

    cin.getline(subject, 50);
    cin.getline(body, 300);
    try {
        EmailMessage emailMessage(sender, receiver, subject, body);
        emailMessage.show();
    } catch (EmailNotValidException & e) {
        e.printMessage();
    }
    return 0;
}

bool valid(char mailAddress[50]) {

//    char *ptr = strstr(mailAddress, "@"); //stefan@finki.ukim.mk //ptr -> @finki.ukim.mk
//    if (ptr == nullptr) {
//        return false;
//    }
//    return strstr(ptr, ".") != nullptr;

    int idx = -1;
    for (int i = 0; i < strlen(mailAddress); i++) {
        if (mailAddress[i] == '@') {
            idx = i;
            break;
        }
    }

    if (idx == -1) { //We haven't found a @
        return false;
    } else {
        for (int i = idx; i < strlen(mailAddress); i++) {
            if (mailAddress[i] == '.')
                return true;
        }
        return false;
    }

}
