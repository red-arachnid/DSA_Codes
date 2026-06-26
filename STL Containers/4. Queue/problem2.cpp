// You're given a stream of integers arriving one at a time (simulate with a vector<int> 
// you iterate through). Using a queue, maintain only the last k elements seen at any point 
// (a sliding window), and after each new element arrives, print the current sum of the window.

#include<bits/stdc++.h>
using namespace std;

void sumOfKElements(const vector<int>& v, int k) {
    queue<int> window;
    int currentSum = 0;

    for (int x : v) {
        if (window.size() >= k) {
            currentSum -= window.front();
            window.pop();
        }

        window.push(x);
        currentSum += x;

        cout << currentSum << "  ";
    }
    cout << "\n\n";
}

int main() {
    vector<int> stream1 = {1, 2, 3, 4, 5};
    int k1 = 3;

    vector<int> stream2 = {5, 5, 5};
    int k2 = 1;

    vector<int> stream3 = {};
    int k3 = 2;

    vector<int> stream4 = {5, 5, 5, 5, 5};
    int k4 = 2;

    sumOfKElements(stream1, k1);
    sumOfKElements(stream2, k2);
    sumOfKElements(stream3, k3);
    sumOfKElements(stream4, k4);

    return 0;
}