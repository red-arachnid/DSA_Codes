// Given an array of integers, find the length of the longest consecutive sequence 
// (e.g., in {100, 4, 200, 1, 3, 2} the answer is 4 from sequence {1,2,3,4}). 
// Do it in O(n) — insert everything into an unordered_set first, then for each element that is a sequence start 
// (meaning x-1 is not in the set), walk forward counting how long the chain goes.

#include<bits/stdc++.h>
using namespace std;

int longestConsecutiveSequence(const vector<int>& v) {
    unordered_set<int> s;
    s.reserve(v.size());
    s.insert(v.begin(), v.end());

    int result = 0;

    for (int x : s) {
        if (!s.count(x-1)) {
            int t = 1;
            while (s.count(x+t)) {
                t++;
            }

            if (t > result) result = t;
        }
    }

    return result;
}

int main() {

    cout << longestConsecutiveSequence({100, 4, 200, 1, 3, 2}) << "\n";
    cout << longestConsecutiveSequence({0, -1, 1, 2, -2}) << "\n";
    cout << longestConsecutiveSequence({1, 2, 3, 4, 5}) << "\n";
    cout << longestConsecutiveSequence({}) << "\n";

    return 0;
}