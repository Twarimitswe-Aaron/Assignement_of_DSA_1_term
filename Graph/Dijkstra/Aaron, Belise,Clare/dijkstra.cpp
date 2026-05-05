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

    // Print all distances
    cout << "Distances from node " << source << ": ";
    for(int i=0;i<n;i++) cout << cost[i] << " ";
    cout << endl;

    // Find minimum distance (excluding source itself)
    int mincost = INT_MAX;
    for(int i=0;i<n;i++){
        if(i != source && cost[i] < mincost)
            mincost = cost[i];
    }

    // Print nodes with the smallest distance
    cout << "Closest node(s) to node " << source << " (distance " << mincost << "): ";
    for(int i=0;i<n;i++){
        if(i != source && cost[i] == mincost)
            cout << i << " ";
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

    return 0;
}
