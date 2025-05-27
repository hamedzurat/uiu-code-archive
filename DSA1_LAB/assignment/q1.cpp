#include <bits/stdc++.h>
using namespace std;

struct Train {
    string id;
    Train* next;

    Train(string id)
    : id(id), next(nullptr) {
    }
};

Train* head = nullptr;

// add new node at the end
void add_train(string& id) {
    Train* t = new Train(id);

    if(!head)
        head = t;
    else {
        Train* last = head;
        while(last->next) last = last->next;
        last->next = t;
    }
}

// find and remove a node
void depart_train(string& id) {
    if(!head) {
        cerr << "ERROR: No trains" << endl;
        return;
    }

    // if at first
    if(head->id == id) {
        Train* tmp = head;
        head       = head->next;
        delete tmp;
        return;
    }

    // find
    Train* now = head;
    while(now->next && now->next->id != id) now = now->next;

    if(!now->next) {
        cerr << "ERROR: Train " << id << " not found" << endl;
        return;
    }

    Train* tmp = now->next;
    now->next  = now->next->next;
    delete tmp;
}

// remove by index
void emergency_block(int index) {
    if(!head) {
        cerr << "ERROR: No trains" << endl;
        return;
    }

    // if head
    if(index == 0) {
        Train* tmp = head;
        string id  = head->id;
        head       = head->next;
        delete tmp;
        return;
    }

    // goto
    Train* now = head;
    for(int i = 0; i < index - 1 && now->next; i++) now = now->next;

    if(!now->next) {
        cerr << "ERROR: No train at " << index << endl;
        return;
    }

    Train* tmp = now->next;
    string id  = now->next->id;
    now->next  = now->next->next;
    delete tmp;
}

void display_tracks() {
    Train* now = head;
    while(now) {
        cout << now->id << " -> ";
        now = now->next;
    }
    cout << "[NOTHING]" << endl;  // for nullptr
}

int main() {
    int opcode;
    string id;

    // menu
    cout << "1. add train <id>" << endl
         << "2. depart train <id>" << endl
         << "3. emergency block <id>" << endl
         << "4. display tracks <id>" << endl
         << "5. quit" << endl
         << endl;

    while(true) {
        cout << "\nEnter command: ";
        cin >> opcode;

        if(opcode == 1) {
            cin >> id;
            add_train(id);
        } else if(opcode == 2) {
            cin >> id;
            depart_train(id);
        } else if(opcode == 3) {
            int index;
            cin >> index;
            emergency_block(index);
        } else if(opcode == 4)
            display_tracks();
        else if(opcode == 5)
            break;
        else
            cerr << "Unknown command." << endl;
    }

    return 0;
}
