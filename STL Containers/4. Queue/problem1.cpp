// Implement a function vector<int> bfsOrder(vector<vector<int>>& adj, int start) that
// performs BFS on a graph given as an adjacency list (adj[i] = list of neighbours of node i) and 
// returns the order in which nodes are visited, starting from start.

#include<bits/stdc++.h>
using namespace std;

//! BFS Algorithm
vector<int> bfsOrder(const vector<vector<int>>& adj, int start) {
    vector<int> result;
    result.reserve(adj.size());
    vector<bool> visited(adj.size(), false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    result.emplace_back(start);

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neightbour : adj[node]) {
            if (!visited[neightbour]) {
                visited[neightbour] = true;
                q.push(neightbour);
                result.emplace_back(neightbour);
            }
        }
    }

    return result;
}


int main() {
    vector<vector<int>> adj1 = {{1,2}, {0,3}, {0,3}, {1,2}};
    int start1 = 0;

    vector<vector<int>> adj2 = {{1},{2},{0}};
    int start2 = 1;

    for (int rs : bfsOrder(adj1, start1)) {
        cout << rs << "  ";
    }
    cout << "\n\n";

    for (int rs : bfsOrder(adj2, start2)) {
        cout << rs << "  ";
    }
    cout << "\n\n";

    return 0;
}