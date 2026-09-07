// You're given a list of (score, name) pairs representing students. Store them in a multimap<int, string> keyed by score. Then:
// 1. Print all students sorted by score ascending.
// 2. Print all students who scored exactly k (use equal_range).
// 3. Print the top 3 scorers (handle ties — if 3rd place is tied, print all tied students at that score).

#include<bits/stdc++.h>
using namespace std;

void printStudentInAscendingOrderOfScore(const multimap<int, string>& mm) {
    for (auto [key, value] : mm) {
        cout << value << ":" << key << ", ";
    }
    cout << "\n";
}

void printStudentWithScoreK(const multimap<int, string>& mm, int k) {
    auto [lo, hi] = mm.equal_range(k);
    for (auto it = lo; it != hi; it++) {
        cout << it->second << ", ";
    }
    cout << "\n";
}

void printTopScoringStudents(const multimap<int, string>& mm) {
    int counter = 0;
    optional<int> prevScore = nullopt;

    for (auto it = mm.rbegin(); it != mm.rend(); it++) {
        if (prevScore.has_value() && prevScore == it->first) continue;

        auto [lo, hi] = mm.equal_range(it->first);
        for (auto inIt = lo; inIt != hi; inIt++) {
            cout << inIt->second << "(" << inIt->first << "), ";
            counter++;
        }
        
        prevScore = it->first;
        if (counter >= 3) break;
    }
    cout << "\n";
}

int main() {
    multimap<int, string> mm({
        {85, "Alice"},
        {92, "Bob"},
        {85, "Charlie"},
        {78, "Dave"},
        {92, "Eve"},
        {88, "Frank"},
        {88, "Aryan"}
    });

    printStudentInAscendingOrderOfScore(mm);
    printStudentWithScoreK(mm, 85);
    printTopScoringStudents(mm);

    return 0;
}