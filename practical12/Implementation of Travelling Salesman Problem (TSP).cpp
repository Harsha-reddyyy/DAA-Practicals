
#include <iostream>
#include <climits>
using namespace std;

#define N 4

int tsp(int cost[N][N], int city, int visited) {
    if (visited == (1 << N) - 1)
        return cost[city][0];

    int ans = INT_MAX;

    for (int i = 0; i < N; i++) {
        if (!(visited & (1 << i))) {
            int newCost = cost[city][i] +
                tsp(cost, i, visited | (1 << i));

            if (newCost < ans)
                ans = newCost;
        }
    }

    return ans;
}

int main() {
    int cost[N][N] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    cout << "Minimum travelling cost: "
         << tsp(cost, 0, 1);

    return 0;
}
