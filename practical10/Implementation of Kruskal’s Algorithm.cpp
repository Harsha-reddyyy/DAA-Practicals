
#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    int src, dest, weight;
};

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

int parent[10];

int find(int v) {
    if (parent[v] == v)
        return v;
    return parent[v] = find(parent[v]);
}

void unite(int u, int v) {
    parent[find(u)] = find(v);
}

int main() {
    int V = 4, E = 5;

    Edge edges[] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    sort(edges, edges + E, compare);

    for (int i = 0; i < V; i++)
        parent[i] = i;

    int total = 0;
    cout << "Edges in MST:\n";

    for (int i = 0, count = 0; i < E && count < V - 1; i++) {
        int u = edges[i].src;
        int v = edges[i].dest;

        if (find(u) != find(v)) {
            cout << u << " - " << v
                 << " : " << edges[i].weight << "\n";

            unite(u, v);
            total += edges[i].weight;
            count++;
        }
    }

    cout << "Total MST Weight: " << total;

    return 0;
}
