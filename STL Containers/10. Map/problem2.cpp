// You're given a list of intervals (start, end) arriving one at a time. After each new interval is inserted,
// print whether the new interval overlaps with any existing interval already stored. Use a map<int,int> where key = start, 
// value = end, and use lower_bound to efficiently find the nearest interval that could overlap. 
// don't do a linear scan of all stored intervals.
// Two intervals (s1,e1) and (s2,e2) overlap if s1 < e2 && s2 < e1 
// (they share at least one point exclusively. Touching endpoints don't count as overlap).

#include<bits/stdc++.h>
using namespace std;


void insertWithoutOverlap(map<int,int> m, int start, int end) {
    if (m.empty()) {
        cout << "No Overlap - First Element Inserted\n";
        m.insert({start, end});
        return;
    }

    auto it = m.lower_bound(start);

    if (it != m.end() && it->first < end) {
        cout << "(" << start << "," << end << ") overlapped with (" << it->first << "," << it->second << ")\n";
        return;
    }

    if (it != m.begin()) {
        auto prevIt = prev(it);
        if (prevIt->second > start) {
            cout << "(" << start << "," << end << ") overlapped with (" << prevIt->first << "," << prevIt->second << ")\n";
            return;
        }
    }

    cout << "No Overlap\n";
    m.insert({start, end});
    return;
}

int main() {
    map<int, int> m;
    insertWithoutOverlap(m,1,5);
    insertWithoutOverlap(m,6,10);
    insertWithoutOverlap(m,-2,1);
    insertWithoutOverlap(m,4,7);
    insertWithoutOverlap(m,11,15);
    insertWithoutOverlap(m,5,6);

    return 0;
}