#include <bits/stdc++.h>
using namespace std;

struct Term {
    int coefficient;
    int exponent;
    Term* next;

    Term(int c, int e)
    : coefficient(c), exponent(e), next(nullptr) {
    }
};

struct Polynomial {
    Term* head = nullptr;
    Term* tail = nullptr;
};

void add(Polynomial& poly, int c, int e) {
    if(c == 0) return;

    Term* t = new Term(c, e);

    // when empty
    if(!poly.head) {
        poly.head = t;
        return;
    }

    // when exopnent is highest
    if(e > poly.head->exponent) {
        t->next   = poly.head;
        poly.head = t;
        return;
    }

    Term* now  = poly.head;
    Term* prev = nullptr;  // to delete a node from the middle

    // find
    while(now && now->exponent > e) {
        prev = now;
        now  = now->next;
    }

    // when same exponent
    if(now && now->exponent == e) {
        now->coefficient += c;
        delete t;

        // remove term when its meaning less
        if(now->coefficient == 0) {
            if(prev)
                prev->next = now->next;
            else
                poly.head = now->next;

            delete now;
        }
        return;
    }

    // inset while being sorted
    t->next = now;
    if(prev)
        prev->next = t;
    else
        poly.head = t;
}

// https://cplusplus.com/reference/string/string/find/
// https://en.cppreference.com/w/cpp/string/basic_string/stol
void parse_term(Polynomial& poly, const string& term) {
    if(term.empty()) return;

    int c = 0, e = 0;
    size_t x   = term.find('x');
    size_t pow = term.find('^');

    // if only num
    if(x == string::npos) {
        c = stoi(term);
        e = 0;  // by default
    } else {
        // coefficient part
        string prefix = term.substr(0, x);
        if(prefix.empty() || prefix == "+")  // by default
            c = 1;
        else if(prefix == "-")
            c = -1;
        else
            c = stoi(prefix);

        // exponent part
        if(pow != string::npos)
            e = stoi(term.substr(pow + 1));
        else
            e = 1;  // by default
    }

    // cout << "term: " << term << " | c=" << c << " | e=" << e << endl;

    add(poly, c, e);
}

// https://cplusplus.com/reference/string/string/substr/
// https://stackoverflow.com/questions/18565167/non-const-lvalue-references-cannot-be-bound-to-an-lvalue-of-different-type
void parse_polynomial(Polynomial& poly, const string& input) {
    // remove all spaces
    string s;
    for(char c : input)
        if(c != ' ') s += c;

    // first term has `+` sign if non is there
    if(s[0] != '+' && s[0] != '-') s = '+' + s;

    // cout << "uniform: " << s << endl;

    // walk & split
    size_t start = 0;
    for(size_t i = 1; i < s.size(); ++i)
        if(s[i] == '+' || s[i] == '-') {
            parse_term(poly, s.substr(start, i - start));
            start = i;
        }

    // last term
    parse_term(poly, s.substr(start));
}

Polynomial add_polys(Polynomial& poly1, Polynomial& poly2) {
    Polynomial sum;

    // copy poly1 to sum
    for(Term* t = poly1.head; t != nullptr; t = t->next)
        add(sum, t->coefficient, t->exponent);

    // add each term to sum
    for(Term* t = poly2.head; t != nullptr; t = t->next)
        add(sum, t->coefficient, t->exponent);

    return sum;
}

void display_polynomial(const Polynomial& poly) {
    // when nothing left after add
    if(!poly.head) {
        cout << "0";
        return;
    }

    for(Term* i = poly.head; i != nullptr; i = i->next) {
        int c     = i->coefficient;
        int e     = i->exponent;
        int abs_c = abs(c);

        // dont print `+` before the first term
        if(i != poly.head) {
            if(c >= 0)
                cout << " + ";
            else
                cout << " - ";
        } else if(c < 0)
            cout << "-";

        if(e == 0)
            cout << abs_c;
        else {
            if(abs_c != 1) cout << abs_c;
            cout << "x";
            if(e != 1) cout << "^" << e;
        }
    }
}


int main() {
    Polynomial poly1, poly2;
    string input1, input2;

    cout << "Enter first polynomial: ";
    getline(cin, input1);
    parse_polynomial(poly1, input1);

    cout << "Enter second polynomial: ";
    getline(cin, input2);
    parse_polynomial(poly2, input2);

    // cout << endl
    //      << "Polynomial 1: ";
    // display_polynomial(poly1);
    // cout << endl
    //      << "Polynomial 2: ";
    // display_polynomial(poly2);

    cout << endl
         << "Sum: ";
    display_polynomial(add_polys(poly1, poly2));
    cout << endl;

    return 0;
}
