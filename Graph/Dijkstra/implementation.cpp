#include <iostream>
#include <climits>
using namespace std;

void Dijkstra(int costMatrix[5][5], int n, int source){
    bool selected[n]; // univisted nodes as index
    int cost[n]; //cost from the source to any node as index

    for(int i=0;i<n;i++){ //initialization of selected and cost
        cost[i] = INT_MAX;
        selected[i] = false;
    }
    cost[source] = 0; //self pointed ie: zero cost

    for(int count=0; count<n-1; count++){ //loop nodes by decreasing until finished
        int u = -1;
        for(int i=0;i<n;i++){
            if(!selected[i] && (u==-1 || cost[i]<cost[u])) 
                u = i;
        }

        selected[u] = true;

        for(int v=0; v<n; v++){
            if(costMatrix[u][v] != 0 && !selected[v] && cost[u] != INT_MAX &&
               cost[u] + costMatrix[u][v] < cost[v]) {
                cost[v] = cost[u] + costMatrix[u][v];
            }
        }
    }

    // Print all costances
    cout << "costances from node " << source << ": ";
    for(int i=0;i<n;i++) cout << cost[i] << " ";
    cout << endl;

    // Find minimum costance (excluding source itself)
    int mincost = INT_MAX;
    for(int i=0;i<n;i++){
        if(i != source && cost[i] < mincost)
            mincost = cost[i];
    }

    // Print nodes with the smallest costance
    cout << "Closest node(s) to node " << source << " (costance " << mincost << "): ";
    for(int i=0;i<n;i++){
        if(i != source && cost[i] == mincost)
            cout << i << " ";
    }
    cout << endl << endl;
}

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
    cout << endl << endl;
}

void FloydWarshall(int costMatrix[5][5], int n) {
    int dist[n][n];

    // Initialize distance matrix
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i == j) dist[i][j] = 0;
            else if(costMatrix[i][j] != 0) dist[i][j] = costMatrix[i][j];
            else dist[i][j] = 10000; // Use a high value for infinity
        }
    }

    // Floyd-Warshall algorithm
    for(int k=0; k<n; k++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the final distance matrix
    cout << "Floyd-Warshall all-pairs shortest paths:" << endl;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(dist[i][j] == 10000) cout << "INF ";
            else cout << dist[i][j] << " ";
        }
        cout << endl;
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
    cout << "--- Dijkstra Algorithm ---" << endl;
    Dijkstra(arr, n, source);

    cout << "--- Bellman-Ford Algorithm ---" << endl;
    BellmanFord(arr, n, source);

    cout << "--- Floyd-Warshall Algorithm ---" << endl;
    FloydWarshall(arr, n);

    return 0;
}