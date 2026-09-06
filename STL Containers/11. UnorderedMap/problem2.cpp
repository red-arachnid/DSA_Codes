// Given an array of integers and a target sum k, find the number of contiguous subarrays that sum to exactly k

#include<bits/stdc++.h>
using namespace std;

int countSubarraysWithSum(const vector<int>& arr, int k) {
    if (arr.size() == 0) return 0;

    unordered_map<int, int> prefix;
    prefix[0] = 1;

    int currentSum = 0;
    int result = 0;

    for (int n : arr) {
        currentSum += n;
        int compliment = currentSum - k;
        if (prefix.find(compliment) != prefix.end()) {
            result += prefix[compliment];
        }

        prefix[currentSum]++;
    }

    return result;
}

int main() {
    cout << countSubarraysWithSum({1,1,1}, 2) << "\n";
    cout << countSubarraysWithSum({1,2,3}, 3) << "\n";
    cout << countSubarraysWithSum({-1, 1, 0}, 0) << "\n";

    return 0;
}