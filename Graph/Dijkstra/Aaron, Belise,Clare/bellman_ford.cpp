#include <iostream>
#include <climits>
using namespace std;

void BellmanFord(int costMatrix[5][5], int n, int source) {
    int cost[n];
    for(int i=0; i<n; i++) cost[i] = INT_MAX;
    cost[source] = 0;

    // Relax all edges n-1 times
    for(int i=0; i<n-1; i++) {
        for(int u=0; u<n; u++) {
            for(int v=0; v<n; v++) {
                if(costMatrix[u][v] != 0 && cost[u] != INT_MAX && 
                   cost[u] + costMatrix[u][v] < cost[v]) {
                    cost[v] = cost[u] + costMatrix[u][v];
                }
            }
        }
    }

    // Check for negative weight cycles
    for(int u=0; u<n; u++) {
        for(int v=0; v<n; v++) {
            if(costMatrix[u][v] != 0 && cost[u] != INT_MAX && 
               cost[u] + costMatrix[u][v] < cost[v]) {
                cout << "Graph contains negative weight cycle" << endl;
                return;
            }
        }
    }

    // Print all distances
    cout << "Bellman-Ford distances from node " << source << ": ";
    for(int i=0; i<n; i++) cout << (cost[i] == INT_MAX ? -1 : cost[i]) << " ";
    cout << endl;

    // Find closest node(s)
    int mincost = INT_MAX;
    for(int i=0; i<n; i++) {
        if(i != source && cost[i] < mincost) mincost = cost[i];
    }
    cout << "Closest node(s) to node " << source << " (distance " << mincost << "): ";
    for(int i=0; i<n; i++) {
        if(i != source && cost[i] == mincost) cout << i << " ";
    }
    cout << endl;
}

int main() {
    int n = 5;
    int arr[5][5] = {
        {0, 0, 1, 1, 0},
        {0, 0, 1, 1, 0},
        {1, 1, 0, 1, 1},
        {1, 1, 1, 0, 1},
        {0, 0, 1, 1, 0}
    };

    int source = 0; 
    cout << "--- Bellman-Ford Algorithm ---" << endl;
    BellmanFord(arr, n, source);

    return 0;
}
