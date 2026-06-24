// Write a function pair<int,int> minMax(vector<int>& arr) that returns the minimum and maximum of the array as a pair, 
// using only a single pass through the array (no calling min_element/max_element twice). Then write a small driver that reads an array,
// calls your function, and prints "min: X, max: Y"

#include<bits/stdc++.h>
using namespace std;

vector<int> randomNumbers = {30, 21, 123, 12, 934, 11, 12, -123, -943, -1000};

pair<int, int> minMax(vector<int>& arr);

int main() {
    auto minAndMax = minMax(randomNumbers);

    cout << minAndMax.first << "   " << minAndMax.second << "\n";

    return 0;
}

pair<int, int> minMax(vector<int>& arr) {
    int min = arr[0], max = arr[0];

    for (int num : arr) {
        if (num > max) {
            max = num;
        }

        if (num < min) {
            min = num;
        }
    }

    return make_pair(min, max);
}