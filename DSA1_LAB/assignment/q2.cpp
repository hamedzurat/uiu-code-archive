#include <bits/stdc++.h>
using namespace std;

struct Pixel {
    char type;  // 0 or .
    int count;
    Pixel* next;
    Pixel* prev;

    Pixel(char type, int count)
    : type(type), count(count), next(nullptr), prev(nullptr) {
    }
};

struct Line {
    Pixel* head;
    Pixel* tail;
    Line* next;

    Line()
    : head(nullptr), tail(nullptr), next(nullptr) {
    }
};

Line* img = nullptr;

void parse(Line* l, string& str) {
    char type = str[0];
    int count = 1;

    for(unsigned int i = 1; i < str.length(); i++) {  // `unsigned` bc compier mad
        // count continus char
        if(str[i] == type)
            count++;
        // save last continus pixel and restart
        else {
            // cout << "type="<< type << " | count=" << count << endl;
            Pixel* p = new Pixel(type, count);
            if(!l->head)
                l->head = l->tail = p;
            else {
                l->tail->next = p;
                p->prev       = l->tail;
                l->tail       = p;
            }

            type  = str[i];
            count = 1;
        }
    }

    // for the last
    // cout << "type="<< type << " | count=" << count << endl;
    Pixel* p = new Pixel(type, count);
    if(!l->head)
        l->head = l->tail = p;
    else {
        l->tail->next = p;
        p->prev       = l->tail;
        l->tail       = p;
    }
}

void mirror_and_display() {
    Line* l = img;
    int i   = 0;

    cout << endl
         << "Mirrored Image:" << endl;

    // per line
    while(l) {
        cout << "Row " << i << ": ";

        Pixel* tail = l->tail;
        while(tail) {
            for(int j = 0; j < tail->count; j++) cout << tail->type;
            tail = tail->prev;
        }

        cout << endl;
        l = l->next;
        i++;
    }
}

int main() {
    string input;
    int count = 0;

    cout << "num of rows: ";
    cin >> count;
    cin.ignore();  // https://stackoverflow.com/questions/257091/how-do-i-flush-the-cin-buffer

    for(int i = 0; i < count; i++) {
        cout << "Row " << i << ": ";
        getline(cin, input);

        // remove everything but `.` & `0`
        string clean_str;
        for(char c : input)
            if(c == '0' || c == '.') clean_str += c;

        // cout << "clean: " << clean_str << endl;

        Line* l = new Line();
        if(!img)
            img = l;
        else {
            Line* now = img;
            while(now->next) now = now->next;
            now->next = l;
        }

        parse(l, clean_str);
    }

    mirror_and_display();

    return 0;
}
