#include<bits/stdc++.h>
using namespace std;

//! Common DSA patterns that uses bitset

int main() {
    //*Sieve of Eratosthenes : Used to check prime numbers from 0 to MAXN (upper limit 10 million)
    // A vector<bool> will use 10MB to check for 10million numbers while a bitset only user ~1.2MB
    const int MAXN = 1e7;
    bitset<MAXN> is_composite;
    is_composite[0] = is_composite[1] = 1;
    for (int i = 2; i < MAXN; i++) {
        if (!is_composite[i]) {
            for (int j = 2*i; j < MAXN; j += i)
                is_composite[j] = 1;
        }
    }


    //* Knapsack Problem (bitset varient to solve)
    // What is Knapsack Problem:
    // Given a set of items, each with a specific weight and value, determine which items to include in a knapsack 
    // of maximum capacity "W" so that the total value is maximized without exceeding the capacity.
    vector<int> weights = {1, 2, 4, 8, 16};
    bitset<100001> dp;
    dp[0] = 1;
    for (int w : weights) {
        dp |= (dp << w);
    }


    //* Finding union/intersection of set for large boolean array
    bitset<1000> classA, classB;
    bitset<1000> studentOfBothClasses = classA & classB;        // Intersection of those two classes
    studentOfBothClasses.count();                           //Student that are in both clases
    return 0;
}