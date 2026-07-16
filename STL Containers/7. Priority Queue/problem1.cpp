// Given an array of integers, find the k-th largest element using a priority_queue. 
// Do it with a min-heap of size at most k — not by pushing everything and popping k times 
// (though that also works, think about why the min-heap-of-size-k approach is more memory efficient).

#include<bits/stdc++.h>
using namespace std;

int findKthLargest(const vector<int>& vec, int key) {
    priority_queue<int, vector<int>, greater<int>> minpq;

    for (int x : vec) {
        if (minpq.size() < key) {
            minpq.push(x);
            continue;
        }

        if (x > minpq.top()) {
            minpq.pop();
            minpq.push(x);
        }
    }

    return minpq.top();
}

int main() {
    vector<int> arr1 = {3,2,1,5,6,4};
    int key1 = 2;

    vector<int> arr2 = {3,2,3,1,2,4,5,5,6};
    int key2 = 4;

    vector<int> arr3 = {7,7,7,7};
    int key3 = 3;

    cout << key1 << "th largest element of array { ";
    for (int x : arr1) {
        cout << x << ", ";
    }
    cout << "\b\b } is : " << findKthLargest(arr1, key1) << "\n\n";

    cout << key2 << "th largest element of array { ";
    for (int x : arr2) {
        cout << x << ", ";
    }
    cout << "\b\b } is : " << findKthLargest(arr2, key2) << "\n\n";

    cout << key3 << "th largest element of array { ";
    for (int x : arr3) {
        cout << x << ", ";
    }
    cout << "\b\b } is : " << findKthLargest(arr3, key3) << "\n\n";

    return 0;
}