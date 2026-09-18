// Maintain a dynamic running dataset: you're given a sequence of operations, either INSERT x or DELETE x. After each operation, 
// print the median of all current elements. Use two multisets — one for the lower half (max at rbegin()), one for the upper half 
// (min at begin()) — rebalancing after each operation to keep sizes within 1.

#include<bits/stdc++.h>
using namespace std;

class Dataset {
    multiset<int> lower, upper;
    int count;
    

public:
    Dataset(): count(0) {}
    int INSERT(int x) {
        if (count == 0) {
            lower.insert(x);
            count++;
            return x;
        }

        if (x > *lower.rbegin()) {
            upper.insert(x);
        }
        else {
            lower.insert(x);
        }
        count++;

        for (auto it = lower.rbegin(); lower.size() > upper.size() + 1;) {
            upper.insert(*it);
            lower.erase((++it).base());
        }
        for (auto it = upper.begin(); upper.size() > lower.size() + 1; it++) {
            lower.insert(*it);
            upper.erase(it);
        }

        // Calculate the median
        if (count % 2 == 0) {
            return (*lower.rbegin() + *upper.begin()) / 2;
        }
        else {
            return (lower.size() > upper.size()) ? *lower.rbegin() : *upper.begin();
        }
    }

    int DELETE(int x) {
        if (count == 0) {
            throw runtime_error("Dataset is empty");
        }

        if (x > *lower.rbegin()) {
            upper.erase(upper.find(x));
        }
        else {
            lower.erase(lower.find(x));
        }
        count--;

        for (auto it = lower.rbegin(); lower.size() > upper.size() + 1;) {
            upper.insert(*it);
            lower.erase((++it).base());
        }
        for (auto it = upper.begin(); upper.size() > lower.size() + 1; it++) {
            lower.insert(*it);
            upper.erase(it);
        }

        // Calculate the median
        if (count % 2 == 0) {
            return (*lower.rbegin() + *upper.begin()) / 2;
        }
        else {
            return (lower.size() > upper.size()) ? *lower.rbegin() : *upper.begin();
        }
    }
};

int main() {
    Dataset d;
    cout << d.INSERT(5) << "\n";
    cout << d.INSERT(3) << "\n";
    cout << d.INSERT(8) << "\n";
    cout << d.INSERT(3) << "\n";
    cout << d.DELETE(3) << "\n";
    cout << d.DELETE(5) << "\n";
    return 0;
}