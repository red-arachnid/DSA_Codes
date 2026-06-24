// You're given n pairs of (arrival_time, employee_id) representing when employees badge into office. 
// Sort them so employees are listed in order of arrival time; if two arrive at the exact same time, 
// the one with the smaller employee_id should come first. Print the sorted list of employee_ids

#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> empLog = {{100, 4}, {434, 31}, {23, 34}, {12, 101}, {204, 11}, {204, 3}};

int main() {

    sort(empLog.begin(), empLog.end());

    for (auto emp : empLog) {
        cout << emp.first << " - " << emp.second << "\n";
    }

    return 0;
}