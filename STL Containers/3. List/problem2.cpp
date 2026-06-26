// You're given two already sorted lists of integers. Merge them into a single sorted list using splice 
// (not by copying elements into a new container) — i.e., move nodes directly from the two input lists into a result list,
// maintaining sorted order, leaving the two originals empty (or partially empty if you consume them as you go) at the end. 
// You may not use the built-in .merge() member function — implement the merge logic yourself using iterators and splice.

#include<bits/stdc++.h>
using namespace std;

void mergeListsInSortedOrder(list<int>& l1, list<int>& l2) {
    // Main changes happens in l1, l2 is set to empty.
    auto ita = l1.begin();
    auto itb = l2.begin();
    auto endItb = l2.begin();
    endItb++;

    while (ita != l1.end() && itb != l2.end()) {
        if (*ita > *itb) {
            if (*endItb < *ita) {
                endItb++;
            }
            else {
                l1.splice(ita, l2, itb, endItb);
                itb = endItb;
                endItb++;
            }
        }
        else {
            ita++;
        }
    }

    l1.splice(ita, l2); // Place all the leftover elements of l2 in l1
    // ita here should technically be l1.end() 
}

int main() {
    list<int> l1a = {1, 3, 5}, l1b = {2, 4, 6};
    list<int> l2a = {1, 1, 2}, l2b = {1, 3};

    mergeListsInSortedOrder(l1a, l1b);
    mergeListsInSortedOrder(l2a, l2b);

    // auto it = l1a.begin();
    // auto endItb = l1b.begin();
    // advance(it, 2); // 5
    // advance(endItb, 2); // 6
    // l1a.splice(it, l1b, l1b.begin(), endItb);

    for (auto it = l1a.begin(); it != l1a.end(); it++) {
        cout << *it << "  ";
    }
    cout << "\n\n";

    for (auto it = l2a.begin(); it != l2a.end(); it++) {
        cout << *it << "  ";
    }
    cout << "\n\n";

}