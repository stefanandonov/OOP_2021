//
// Created by Stefan Andonov on 3/24/21.
//


#include<iostream>
#include<cstring>

using namespace std;

class WebPage {
private:
    char url[100];
    char *content;

    void copy(const WebPage &wp) {
        strcpy(this->url, wp.url);
        this->content = new char [strlen(wp.content)+1];
        strcpy(this->content, wp.content);
    }

public:
    WebPage(char *url = "https://finki.ukim.mk", char *content = "FINKI") {
        strcpy(this->url, url);
        this->content = new char [strlen(content)+1];
        strcpy(this->content, content);
    }

    WebPage (const WebPage & wp) {
        copy(wp);
    }

    WebPage & operator = (const WebPage & wp) {
        if (this!=&wp){
            delete [] content;
            copy(wp);
        }
        return *this;
    }

    ~WebPage() {
        delete [] content;
    }

    bool eq (const WebPage & p) {
        return strcmp(this->url, p.url)==0;
    }
};

class WebServer{
private:
    char name [30];
    WebPage * webPages; //strlen(webPages)XXXXXXXXX
    int size;

    void copy (const WebServer & ws) {
        strcpy(this->name,ws.name);
        this->size = ws.size;
//        strcpy(this->webPages, ws.webPages); NAJGOLEMA GRESKA
        this->webPages = new WebPage[this->size];
        for (int i=0;i<this->size;i++) {
            this->webPages[i]=ws.webPages[i];
        }
    }
public:
    WebServer(char * name = "FINKICluster") {
        strcpy(this->name,name);
        size = 0;
        webPages = new WebPage [0];
    }

    WebServer (const WebServer & ws) { // WebServer s (s1);
        copy(ws);
    }

    WebServer & operator = (const WebServer & ws) {  //WebServer s,s1; s=s1;
        if (this!=&ws) {
            delete [] webPages;
            copy(ws);
        }
        return *this;
    }


};

int main() {
    return 0;
}