// Given an array of integers and a value k, find all pairs (a, b) in the array such that a + b = k. 
// Use a set to avoid a nested O(n²) loop — walk the array once, and for each element check if its complement 
// exists in the set of elements seen so far. Print each pair once (no duplicates like printing both (2,3) and (3,2)).

#include<bits/stdc++.h>
using namespace std;

set<pair<int, int>> twoSumPairs(const vector<int>& vec, int sum) {
    set<pair<int,int>> result;
    set<int> s;

    for (int x : vec) {
        int complement = sum - x;

        if (s.find(complement) != s.end()) {
            result.insert({min(x, complement), max(x, complement)});
        }

        s.insert(x);
    }

    return result;
}

int main() {
    for (auto x : twoSumPairs({1,2,3,4,5}, 6)) {
        cout << "[" << x.first << ", " << x.second << "]\n";
    }
    cout << "\n\n";

    for (auto x : twoSumPairs({3,3}, 6)) {
        cout << "[" << x.first << ", " << x.second << "]\n";
    }
    cout << "\n\n";

    return 0;
}