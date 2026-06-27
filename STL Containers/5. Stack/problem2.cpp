// Implement an iterative (non-recursive) DFS traversal: 
// vector<int> dfsOrder(vector<vector<int>>& adj, int start), using an explicit 
// stack instead of recursion, returning nodes in visited order.

#include<bits/stdc++.h>
using namespace std;

// !DFS Algorithm
vector<int> dfsOrder(vector<vector<int>>& adj, int start) {
    vector<int> result;
    result.reserve(adj.size());
    vector<bool> visited(adj.size(), false);
    stack<int> s;

    result.emplace_back(start);
    s.push(start);
    visited[start] = true;

    while(!s.empty()) {
        int node = s.top();
        bool hasChild = false;

        for (int neightbour : adj[node]) {
            if (!visited[neightbour]) {
                s.push(neightbour);
                visited[neightbour] = true;
                result.emplace_back(neightbour);
                hasChild = true;
                break;
            }
        }

        if (!hasChild) s.pop();
            
    }

    return result;
}

int main() {
    vector<vector<int>> adj1 = {{1,2}, {0,3}, {0,3}, {1,2}};
    int start1 = 0;

    vector<vector<int>> adj2 = {{1},{2},{0}};
    int start2 = 1;
    
    vector<vector<int>> adj3 = {{1}, {0,2}, {1}};
    int start3 = 0;

    for (int rs : dfsOrder(adj1, start1)) {
        cout << rs << "  ";
    }
    cout << "\n";

    for (int rs : dfsOrder(adj2, start2)) {
        cout << rs << "  ";
    }
    cout << "\n";

    for (int rs : dfsOrder(adj3, start3)) {
        cout << rs << "  ";
    }
    cout << "\n";

    return 0;
}