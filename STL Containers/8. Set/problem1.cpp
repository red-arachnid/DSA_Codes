// Given an array of integers, for each element arr[i] find the closest element to it that has 
// already been seen (i.e., exists among arr[0..i-1]). "Closest" means minimum absolute difference. 
// If there's a tie (e.g., seen {3, 7} and current element is 5 — both 3 and 7 are equally close), 
// print the smaller one. For the first element, print -1 (nothing seen yet).

#include<bits/stdc++.h>
using namespace std;

vector<int> findClosestPerElement(const vector<int>& vec) {
    vector<int> result; result.reserve(vec.size());
    set<int> s;

    for (int i = 0; i < vec.size(); i++) {
        int x = vec[i];

        if (s.empty()) {
            result.push_back(-1);
        }
        else {
            auto it = s.lower_bound(x);

            if (it == s.begin()) {
                result.push_back(*it);
            }
            else if (it == s.end()) {
                result.push_back(*prev(it));
            }
            else {
                int right = *it;
                int left = *prev(it);

                if (x - left <= right - x) {
                    result.push_back(left);
                }
                else {
                    result.push_back(right);
                }
            }
        }

        s.insert(x);
    }

    return result;
}

int main() {
    for (int x : findClosestPerElement({5, 3, 7, 1, 4})) {
        cout << x << "  ";
    }
    cout << "\n";

    return 0;
}