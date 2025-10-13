#include <bits/stdc++.h>
using namespace std;

class RodCutting {
    public:
    map<int, int> lengthPrice;  // length -> price mapping
    vector<int> dp;
    vector<int> cut;  // To track where cuts were made

    void addPrice(int length, int price) {
        lengthPrice[length] = price;
    }

    int solve(int n) {
        dp.resize(n + 1, 0);
        cut.resize(n + 1, 0);

        // dp[i] = maximum revenue obtainable from rod of length i
        for(int i = 1; i <= n; i++) {
            int maxVal  = 0;
            int bestCut = 0;

            // Try all possible first cuts
            for(auto& p : lengthPrice) {
                int len   = p.first;
                int price = p.second;

                if(len <= i) {
                    if(price + dp[i - len] > maxVal) {
                        maxVal  = price + dp[i - len];
                        bestCut = len;
                    }
                }
            }

            dp[i]  = maxVal;
            cut[i] = bestCut;
        }

        return dp[n];
    }

    void printSolution(int n) {
        int maxRevenue = solve(n);

        cout << "\n======================================\n";
        cout << "ROD CUTTING SOLUTION\n";
        cout << "======================================\n";
        cout << "Rod length: " << n << " inches\n";
        cout << "Maximum revenue: " << maxRevenue << endl;

        // Reconstruct the cuts
        vector<int> pieces;
        int remaining = n;

        while(remaining > 0) {
            int cutLength = cut[remaining];
            if(cutLength == 0) break;
            pieces.push_back(cutLength);
            remaining -= cutLength;
        }

        if(pieces.empty()) {
            cout << "\nOptimal strategy: Don't cut the rod\n";
            cout << "Sell entire rod of length " << n << endl;
        } else {
            cout << "\nOptimal cuts:\n";

            // Count frequency of each piece length
            map<int, int> freq;
            for(int p : pieces) {
                freq[p]++;
            }

            cout << "Cut into " << pieces.size() << " piece(s):\n";
            for(auto& f : freq) {
                cout << "  - " << f.second << " piece(s) of length " << f.first << endl;
            }

            cout << "\nPiece breakdown:\n";
            for(int p : pieces) {
                cout << "  Length " << p << " -> Price " << lengthPrice[p] << endl;
            }
        }
    }
};

int main() {
    RodCutting rc;

    // Add prices from the table
    rc.addPrice(1, 2);
    rc.addPrice(3, 8);
    rc.addPrice(4, 9);
    rc.addPrice(5, 10);
    rc.addPrice(7, 20);
    rc.addPrice(8, 22);

    cout << "Price Table:\n";
    cout << "Length | Price\n";
    cout << "-------|------\n";
    for(auto& p : rc.lengthPrice) {
        cout << "   " << p.first << "   |  " << p.second << endl;
    }

    // Test case 1: n = 3
    cout << "\n\n========== TEST CASE 1 ==========";
    rc.printSolution(3);

    // Test case 2: n = 5
    cout << "\n\n========== TEST CASE 2 ==========";
    rc.printSolution(5);

    // Test case 3: n = 8
    cout << "\n\n========== TEST CASE 3 ==========";
    rc.printSolution(8);

    // Test case 4: n = 10
    cout << "\n\n========== TEST CASE 4 ==========";
    rc.printSolution(10);

    return 0;
}

/*
ROD CUTTING - DYNAMIC PROGRAMMING
==================================

PROBLEM:
--------
Given a rod of length n and prices for different lengths,
find the maximum revenue by cutting the rod optimally.

APPROACH:
---------
Use dynamic programming to try all possible cuts and
choose the one that gives maximum revenue.

STATE DEFINITION:
-----------------
dp[i] = maximum revenue obtainable from rod of length i

RECURRENCE RELATION:
--------------------
dp[i] = max(price[j] + dp[i-j]) for all valid lengths j

where:
- price[j] = price of piece of length j
- dp[i-j] = maximum revenue from remaining length (i-j)

BASE CASE:
----------
dp[0] = 0 (no rod, no revenue)

ALGORITHM:
----------
1. For each length i from 1 to n:
   - Try cutting a piece of every available length j
   - Calculate: price[j] + dp[i-j]
   - Keep track of maximum value
   - Store which cut gave maximum (for reconstruction)

2. dp[n] gives the maximum revenue

3. Use cut[] array to reconstruct the solution:
   - cut[i] stores the length of first piece cut from rod of length i
   - Backtrack to find all pieces

TIME COMPLEXITY: O(n * k)
- n = rod length
- k = number of different prices available

SPACE COMPLEXITY: O(n)
- dp array and cut array

EXAMPLE (from assignment):
--------------------------
Length: 1  3  4  5  7  8
Price:  2  8  9  10 20 22

For n = 5:
- dp[1] = 2 (length 1)
- dp[2] = 4 (two pieces of length 1)
- dp[3] = 8 (one piece of length 3)
- dp[4] = max(9, 2+8) = 10 (length 1 + length 3)
- dp[5] = max(10, 2+10, 2+8) = 12 (two length 1 + one length 3)

Optimal: 1+1+3 = 5, Revenue = 2+2+8 = 12

For n = 3:
- dp[3] = 8 (don't cut, sell entire piece)

KEY INSIGHT:
------------
This is similar to unbounded knapsack - we can use the same
piece length multiple times. The difference is we're trying
to maximize value while exactly using capacity n.
*/
