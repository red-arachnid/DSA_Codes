// Given a list<int>, use only iterator operations (no [], no converting to vector) to:
// 1. Find and print the middle element using the slow/fast pointer technique
// 2. Then erase all elements in the second half of the list (from middle to end)

#include<bits/stdc++.h>
using namespace std;

void reduceToHalf(list<int>& l) {
    if (l.empty()) return;

    list<int>::iterator slow, fast;
    slow = fast = l.begin();

    while (fast != l.end() && fast != prev(l.end())) {
        advance(slow, 1);
        advance(fast, 2);
    }
    cout << "Middle Element: " << *slow << '\n';
    l.erase(next(slow), l.end());
}

int main() {
    list<int> l1 = {1,2,3,4,5};
    reduceToHalf(l1);
    for (int x : l1) {
        cout << x << ' ';
    }
    cout << '\n';

    list<int> l2 = {1,2,3,4,5,6};
    reduceToHalf(l2);
    for (int x : l2) {
        cout << x << ' ';
    }
    cout << '\n';
}