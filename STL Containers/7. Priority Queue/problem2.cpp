// You're given k sorted arrays (each individually sorted in ascending order). 
// Merge them into one sorted array using a min-heap. The min-heap should store 
// (value, array_index, element_index) tuples so you always know which array to pull the next element from.

#include<bits/stdc++.h>
using namespace std;

using Tuple = tuple<int, int, int>;

vector<int> mergeSortedArrays(const vector<vector<int>>& arrs) {
    auto comp = [](const Tuple& a, const Tuple& b) {
        return get<0>(a) > get<0>(b);
    };
    
    priority_queue<Tuple, vector<Tuple>, decltype(comp)> minpq(comp);
    vector<int> result;

    for (int i = 0; i < arrs.size(); i++) {
        if (!arrs[i].empty()) {
            minpq.push({arrs[i][0], i, 0});
        }
    }

    while (!minpq.empty()) {
        auto [val, arrIndex, elIndex] = minpq.top();
        minpq.pop();

        result.push_back(val);

        int nextElIndex = elIndex + 1;
        if (nextElIndex < arrs[arrIndex].size()) {
            minpq.push({arrs[arrIndex][nextElIndex], arrIndex, nextElIndex});
        }
    }

    return result;
}

int main() {
    cout << "Merged Array : ";
    for (int x : mergeSortedArrays({{1,4,7}, {2,5,8}, {3,6,9}})) {
        cout << x << " ";
    }
    cout << "\n\n";

    cout << "Merged Array : ";
    for (int x : mergeSortedArrays({{1,3,5}, {2,4,6}})) {
        cout << x << " ";
    }
    cout << "\n\n";

    cout << "Merged Array : ";
    for (int x : mergeSortedArrays({{1,1}, {1,1}, {1,1}})) {
        cout << x << " ";
    }
    cout << "\n\n";
}