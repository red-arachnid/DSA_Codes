// Given a list of integers representing weights, and a target sum T, determine all 
// possible subset sums achievable using any subset of the weights.

#include<bits/stdc++.h>
using namespace std;

void printAllSumAchievableTillTarget(const vector<int>& weights, int target) {
    bitset<10000> dp;
    dp[0] = 1;
    for (int w : weights) {
        dp |= (dp << w);
    }
    cout << "All possible sum achievable: ";
    for (int i = 0; i <= target; i++) {
        if (dp[i] == 1) cout << i << " ";
    }
    cout << '\n';
}

int main() {
    printAllSumAchievableTillTarget({1,2,3},6);
    printAllSumAchievableTillTarget({3,5},10);
    printAllSumAchievableTillTarget({2,4},5);
}