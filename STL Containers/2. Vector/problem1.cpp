// Implement a function that removes all duplicate elements from a vector<int> in place without 
// using a set, preserving the original order of first occurrence. 

#include<bits/stdc++.h>
using namespace std;

vector<int> v = {123, 123, 23, 10, 43, 546, 334, 13, 10, 32, 23, 55};


void removeDuplicates(vector<int>& vec) {
    for (auto it = vec.begin(); it != vec.end(); ) {
        for (auto i = vec.begin(); i != vec.end(); ) {
            if (it != i && *it == *i) {
                i = vec.erase(i);
            }
            else {
                i++;
            }
        }
        it++;
    }
}

int main() {
    removeDuplicates(v);

    for (int x : v) {
        cout << x << "  ";
    }
    cout << "\n";

    return 0;
}
