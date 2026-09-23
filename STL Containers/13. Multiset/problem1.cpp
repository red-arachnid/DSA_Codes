// Maintain a dynamic running dataset: you're given a sequence of operations, either INSERT x or DELETE x. After each operation, 
// print the median of all current elements. Use two multisets — one for the lower half (max at rbegin()), one for the upper half 
// (min at begin()) — rebalancing after each operation to keep sizes within 1.

#include<bits/stdc++.h>
using namespace std;

class Dataset {
    multiset<int> lower, upper;
    
    void rebalance() {
        if (lower.size() > upper.size() + 1) {
            auto it = prev(lower.end());
            upper.insert(*it);
            lower.erase(it);
        } else if (upper.size() > lower.size()) {
            auto it = upper.begin();
            lower.insert(*it);
            upper.erase(it);
        }
    }

    int median() {
        if ((lower.size() + upper.size()) % 2 == 1) {
            return *lower.rbegin();
        } else {
            return (*lower.rbegin() + *upper.begin()) / 2;
        }
    }

public:
    int INSERT(int val) {
        if (lower.empty() || val <= *lower.rbegin())
            lower.insert(val);
        else
            upper.insert(val);
        rebalance();

        rebalance();
        return median();
    }

    int DELETE(int val) {
        if (val <= *lower.rbegin()) {
            auto it = lower.find(val);
            lower.erase(it);                
        } else {
            auto it = upper.find(val);
            upper.erase(it);
        }

        rebalance();
        return median();
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