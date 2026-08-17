// Given two arrays, find their intersection — elements that appear in both — with no duplicates in the result. 
// Use an unordered_set to do it in O(n + m) rather than O(n × m).

#include<bits/stdc++.h>
using namespace std;

vector<int> intersect(const vector<int>& v1, const vector<int>& v2) {
    vector<int> result; result.reserve(v1.size() + v2.size());
    unordered_set<int> s; s.reserve(v1.size() + v2.size());

    for (int x : v1) {
        if (s.insert(x).second) {
            result.push_back(x);
        }
    }
    for (int x : v2) {
        if (s.insert(x).second) {
            result.push_back(x);
        }
    }

    return result;
}

int main() {
    for (int x : intersect({1,2,3,4}, {3,4,5,6})) {
        cout << x << " ";
    } cout << "\n";

    for (int x : intersect({1,1,2,2}, {2,2,3})) {
        cout << x << " ";
    } cout << "\n";
    return 0;
}