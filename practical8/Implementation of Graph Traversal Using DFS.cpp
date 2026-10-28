#include <iostream>
#include <vector>
using namespace std;

void DFS(int node, vector<int> adj[], bool visited[]) {
    visited[node] = true;
    cout << node << " ";

    for (int i : adj[node]) {
        if (!visited[i]) {
            DFS(i, adj, visited);
        }
    }
}

int main() {
    int vertices = 5;

    vector<int> adj[5];
    bool visited[5] = {false};

    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[1].push_back(4);

    cout << "DFS Traversal: ";
    DFS(0, adj, visited);

    return 0;
}