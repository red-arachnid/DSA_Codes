// Implement the classic sliding window maximum: given an array and window size k, find the maximum of each 
// contiguous window of size k as it slides from left to right. Do it in O(n) total time using a deque to maintain 
// candidate indices (a monotonic deque — keep it decreasing in value front-to-back, popping from the back when a new 
// element invalidates smaller ones, and popping from the front when the front index falls outside the window).

#include<bits/stdc++.h>
using namespace std;

vector<int> slidingWindowMaximum(const vector<int>& nums, const int k) {
    vector<int> result;
    result.reserve(nums.size());

    deque<int> dq;
    
    for (int i = 0; i < nums.size(); i++) {
        if (!dq.empty() && dq.front() < i - k + 1) {
            dq.pop_front();
        }

        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }

        dq.push_back(i);

        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }

    return result;
}


int main() {
    vector<int> v1 = {1,3,-1,-3,5,3,6,7};
    int k1 = 3;

    vector<int> v2 = {4,3,2,1};
    int k2 = 2;

    for (int x : slidingWindowMaximum(v1, k1)) {
        cout << x << "  ";
    }
    cout << "\n\n";

    for (int x : slidingWindowMaximum(v2, k2)) {
        cout << x << "  ";
    }
    cout << "\n\n";

    return 0;
}