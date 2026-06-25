// Implement a function void removeConsecutiveDuplicates(list<int>& l) that removes 
// consecutive duplicate elements from a list without using unique() — walk it manually using 
// iterators.

#include<bits/stdc++.h>
using namespace std;

void removeConsecutiveDuplicates(list<int>& l) {
    int prevValue = l.front();
    auto it = l.begin();
    it++;

    while (it != l.end()) {
        if (*it == prevValue) {
            it = l.erase(it);
        }
        else {
            prevValue = *it;
            it++;
        }
    }
}

int main() {
    list<int> l1 = {1, 1, 2, 3, 3, 3, 4};
    list<int> l2 = {1, 1, 1, 1};
    list<int> l3 = {1, 2, 3};
    list<int> l4 = {};

    removeConsecutiveDuplicates(l1);
    removeConsecutiveDuplicates(l2);
    removeConsecutiveDuplicates(l3);
    removeConsecutiveDuplicates(l4);

    for (auto it = l1.begin(); it != l1.end(); it++) {
        cout << *it << "  ";
    }
    cout << "\n\n";

    for (auto it = l2.begin(); it != l2.end(); it++) {
        cout << *it << "  ";
    }
    cout << "\n\n";

    for (auto it = l3.begin(); it != l3.end(); it++) {
        cout << *it << "  ";
    }
    cout << "\n\n";

    for (auto it = l4.begin(); it != l4.end(); it++) {
        cout << *it << "  ";
    }
    cout << "\n\n";

    return 0;
}