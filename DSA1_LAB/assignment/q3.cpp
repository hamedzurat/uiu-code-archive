#include <bits/stdc++.h>
using namespace std;

struct Node {
    char ch;
    int frequency;
    Node* next;

    Node(char ch)
    : ch(ch), frequency(0), next(nullptr) {
    }
};

Node* head = nullptr;
Node* tail = nullptr;  // to easily add new node

Node* find(char ch) {
    Node* now = head;
    while(now) {
        if(now->ch == ch) return now;
        now = now->next;
    }
    return nullptr;
}

int main() {
    string in;

    cout << "Input analyze: ";
    getline(cin, in);

    // init the counter
    for(char ch = 'a'; ch <= 'z'; ch++) {
        Node* n = new Node(ch);

        if(!head)
            head = tail = n;
        else {
            tail->next = n;
            tail       = n;
        }
    }

    // count
    for(char ch : in) {
        ch = tolower(ch);
        if(!islower(ch)) continue;  // skip non alpha
        // cout << ch << endl;

        Node* node = find(ch);
        if(node) node->frequency++;
    }

    // display
    cout << "Frequencies:" << endl;
    Node* now = head;
    while(now) {
        cout << now->ch << " : " << now->frequency << endl;
        now = now->next;
    }

    return 0;
}
