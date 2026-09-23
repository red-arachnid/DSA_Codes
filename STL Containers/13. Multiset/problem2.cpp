// Given an array of integers and a window size k, for each window of size k sliding left to right, 
// print the median of that window. Use two multisets (lower/upper halves) and slide the window by 
// inserting the new element and erasing the outgoing element

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

public:
    void insert(int val) {
        if (lower.empty() || val <= *lower.rbegin())
            lower.insert(val);
        else
            upper.insert(val);
        rebalance();

        rebalance();
    }

    void remove(int val) {
        if (val <= *lower.rbegin()) {
            auto it = lower.find(val);
            lower.erase(it);                
        } else {
            auto it = upper.find(val);
            upper.erase(it);
        }

        rebalance();
        
    }

    int median(int k) {
        if (k % 2 == 1) {
            return *lower.rbegin();
        } else {
            return (*lower.rbegin() + *upper.begin()) / 2;
        }
    }
};

void slidingWindowMedian(const vector<int>& arr, int k) {
    Dataset ms;
    for (int i = 0; i < arr.size(); i++) {
        ms.insert(arr[i]);
 
        if (i >= k - 1) {
            cout << ms.median(k) << " ";
 
            int outgoing = arr[i - k + 1];
            ms.remove(outgoing);
        }
    }
    cout << "\n";
}

int main() {
    slidingWindowMedian({1,3,2,5,4}, 3);
    slidingWindowMedian({1,2,3,4,5}, 1);
    slidingWindowMedian({5,4,3,2,4}, 2);
    return 0;
}