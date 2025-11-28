#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* next;

    node(int i) {
        data = i;
        next = nullptr;
    }
};

node* Qhead = nullptr;
node* Qtail = nullptr;

void enQ(int i) {
    node* tmp = new node(i);

    if(Qhead == nullptr) {
        Qhead = tmp;
        Qtail = tmp;
    } else {
        Qtail->next = tmp;
        Qtail       = tmp;
    }
}

int deQ() {
    if(Qhead != nullptr) {
        node* head = Qhead;
        int ret    = head->data;
        Qhead      = head->next;
        delete head;
        return ret;
    } else {
        cout << "underflow. returning zero." << endl;
        return 0;
    }
}

bool isEmpty() {
    if(Qhead == nullptr)
        return true;
    else
        return false;
}

void push(int x) {
    enQ(x);
}

int top() {
    node* now = Qhead;
    while(now != nullptr) {
        if(now->next == nullptr)
            return now->data;
        else
            now = now->next;
    }
}

bool is__empty() {
    if(Qhead == nullptr)
        return true;
    else
        return false;
}


int last    = 0;
bool islast = false;
int pop() {
    if(Qhead != nullptr) {
        int tmp = deQ();
        last    = tmp;
        pop();
        // cout << "EEEE: "  << tmp << " - " << islast << endl;
        if(!islast) enQ(tmp);
        islast = false;

        // rev the queue
        int t = deQ();
        pop();
        enQ(t);

        return last;
    } else {
        islast = true;
    }
}

int main() {
    cout << isEmpty() << endl;
    enQ(10);
    enQ(20);
    enQ(30);
    enQ(40);
    enQ(50);
    cout << isEmpty() << endl;

    node* now = Qhead;
    while(now != nullptr) {
        cout << now->data << " -> ";
        now = now->next;
    }

    cout << endl
         << endl;
    cout << deQ() << endl;
    cout << deQ() << endl;
    cout << deQ() << endl;
    cout << deQ() << endl;
    cout << deQ() << endl;
    cout << deQ() << endl;

    cout << endl
         << endl;

    cout << "stack empty: " << is__empty() << endl;

    push(100);
    push(200);
    push(300);
    push(400);
    push(500);
    push(600);

    cout << top() << endl;

    cout << endl
         << "-------------------" << endl;

    now = Qhead;
    while(now != nullptr) {
        cout << now->data << " -> ";
        now = now->next;
    }
    cout << endl;

    cout << "pop: " << pop() << endl;
    cout << "pop: " << pop() << endl;
    cout << "pop: " << pop() << endl;
    cout << "pop: " << pop() << endl;
    cout << "pop: " << pop() << endl;
    cout << "pop: " << pop() << endl;

    now = Qhead;
    while(now != nullptr) {
        cout << now->data << " -> ";
        now = now->next;
    }

    cout << endl
         << "-------------------" << endl;

    return 0;
}
