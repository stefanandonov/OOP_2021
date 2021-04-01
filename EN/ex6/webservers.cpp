//
// Created by Stefan Andonov on 3/25/21.
//


#include<iostream>

using namespace std;

class WebPage {
private:
    char url[100];
    char *content;

    void copy(const WebPage &webPage) {
        strcpy(this->url, webPage.url);
        this->content = new char[strlen(webPage.content) + 1];
        strcpy(this->content, webPage.content);
    }

public:
    WebPage(char *url = "https://finki.ukim.mk",
            char *content = "Faculty of computer science and engineering") {
        strcpy(this->url, url);
        this->content = new char[strlen(content) + 1];
        strcpy(this->content, content);
    }

    WebPage(const WebPage &wp) {
        copy(wp);
    }

    WebPage &operator=(const WebPage &wp) {
        if (this != &wp) {
            delete[] content;
            copy(wp);
        }
        return *this;
    }

    ~WebPage() {
        delete[] content;
    }

    bool operator == (const WebPage &wp) {
        return strcmp(this->url, wp.url) == 0;
    }

    bool operator != (const WebPage & wp) {
        return strcmp(this->url, wp.url) != 0;
    }

    friend ostream & operator << (ostream & out, const WebPage & wp) {
        return out << wp.url << endl << wp.content << endl;
    }

    void setContent(const char *newContent) {
        delete[] this->content;
        this->content = new char[strlen(newContent) + 1];
        strcpy(this->content, newContent);
    }
};

class WebServer {
    char name[30];
    WebPage *webPages;
    int nOfWebPages;

    void copy(const WebServer &ws) {
        strcpy(this->name, ws.name);
        this->nOfWebPages = ws.nOfWebPages;
        this->webPages = new WebPage[this->nOfWebPages];
        for (int i = 0; i < this->nOfWebPages; i++) {
            this->webPages[i] = ws.webPages[i];
        }
    }

public:
    WebServer(char *name = "FINKI cluster") {
        strcpy(this->name, name);
        nOfWebPages = 0;
        webPages = new WebPage[nOfWebPages];
    }

    WebServer(const WebServer &ws) {
        copy(ws);
    }

    WebServer &operator=(const WebServer &ws) {
        if (this != &ws) {
            delete[] webPages;
            copy(ws);
        }
        return *this;
    }

    ~WebServer() {
        delete[] webPages;
    }

    bool contains(const WebPage &wp) {
        for (int i = 0; i < nOfWebPages; i++) {
            if (webPages[i]==wp)
                return true;
        }
        return false;
    }

    WebServer & operator +=(const WebPage &wp) {
        if (!contains(wp)) {
            WebPage *tmp = new WebPage[nOfWebPages + 1];
            for (int i = 0; i < nOfWebPages; i++)
                tmp[i] = webPages[i];
            tmp[nOfWebPages++] = wp;
            delete[] webPages;
            webPages = tmp;
        } else {
            cout << "The webpage already exists!" << endl;
        }
        return *this;
    }

    WebServer & operator -= (const WebPage &wp) {
        if (contains(wp)) {
            WebPage *tmp = new WebPage[nOfWebPages - 1];
            int j = 0;
            for (int i = 0; i < nOfWebPages; i++) {
                if (webPages[i]!=wp) {
                    tmp[j++]=webPages[i];
                }
            }
            nOfWebPages--;
            delete [] webPages;
            webPages = tmp;
        }
        return *this;
    }

    friend ostream & operator << (ostream & out, const WebServer & ws){
        out << ws.name << endl;
        for (int i = 0; i < ws.nOfWebPages; i++) {
            out << i + 1 << ". ";
            out<<ws.webPages[i];
        }
        return out;
    }
};

int main() {
    WebPage wp;
    // wp.print();

    WebPage wp1("https://facebook.com", "Facebook");
    WebPage wp2("https://twitter.com", "Twitter");

    WebPage wp3(wp1);
    wp3.setContent("New content");

    WebServer ws("MY_WEB_SERVER");
    ws+=(wp);
    ws+=(wp1);
    ws+=(wp2);
    ws+=(wp3);

    cout<<ws;

    ws-=(wp);
    cout<<"AFTER DELETING"<<endl;
    cout<<ws;


    return 0;
}
