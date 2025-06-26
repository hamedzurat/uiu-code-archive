#include <iostream>
using namespace std;

struct NODE {
    int ID;
    NODE* next;
    NODE(int id)
    : ID(id), next(nullptr) {
    }
};

NODE* add(NODE* last, NODE* n) {
    last->next = n;
    last       = n;
}

int lenght(NODE* i) {
    int count = 0;
    while(i != nullptr) {
        count++;
        i = i->next;
    }

    return count;
}

void createCycle(NODE* head, NODE* last, int ID) {
    NODE* i = head;
    while(i != nullptr) {
        if(i->ID == ID) break;
        i = i->next;
    }

    if(i == nullptr)
        cout << "ID not found." << endl;
    else
        last->next = i;
}

bool isCycle(NODE* head) {
    if(head == nullptr || head->next == nullptr)
        return false;

    NODE* slow = head;
    NODE* fast = head;

    while(fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) return true;
    }

    return false;
}

int main() {
    int opcode;
    NODE* head = nullptr;
    NODE* last = nullptr;

    while(1) {
        cout << "-------------------------------" << endl;
        cout << "0. print" << endl;
        cout << "1. add" << endl;
        cout << "2. size" << endl;
        cout << "3. create cycle" << endl;
        cout << "4. is cycle" << endl;
        cout << "-------------------------------" << endl;
        cout << endl;

        cin >> opcode;

        if(opcode == 0) {
            NODE* i = head;
            if(i == nullptr) {
                cout << "nothing here." << endl;
                continue;
            }
            while(i != nullptr) {
                cout << i->ID << " -> ";
                i = i->next;
            }
            cout << "NULL" << endl;
        } else if(opcode == 1) {
            cout << "id: ";
            int input;
            cin >> input;
            if(head == nullptr) {
                head = new NODE(input);
                last = head;
            } else
                last = add(last, new NODE(input));
        } else if(opcode == 2)
            cout << "size: " << lenght(head) << endl;
        else if(opcode == 3) {
            cout << "id: ";
            int input;
            cin >> input;
            createCycle(head, last, input);
        } else if(opcode == 4) {
            if(isCycle(head) == 1)
                cout << "isCycle: yes" << endl;
            else
                cout << "isCycle: no" << endl;
        }
    }

    return 0;
}
