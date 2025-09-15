#include <bits/stdc++.h>
#include <cctype>
using namespace std;
/*
void printPower(int a, int b)
{
    int x = power(a,abs(b));
    cout << a << " to the power of "<<b <<" : " << ;
    if(b< 0) cout << "1/"<<x;
    else cout<< x;
}*/

int fact(int n) {
    if(n <= 0) return 1;
    return n * fact(n - 1);
}
int sum(int a) {
    if(a == 0) return 0;
    return a % 10 + sum(a / 10);
}

bool Pallindrome(string S, int start, int end) {
    if(start >= end) return true;

    if(S[start] != S[end]) return false;

    return Pallindrome(S, start + 1, end - 1);
}

int main() {
    int a = 4738765;

    // cout << sum(a) ;


    string S = "Refer";
    string n[S.length()];

    for(int i = 0; i < S.length(); i++) {
        n[i] = tolower(S[i]);
    }




    bool x = Pallindrome(n, 0, n.length() - 1);

    cout << "Output: " << x;
}
