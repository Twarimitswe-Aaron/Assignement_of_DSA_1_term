#include <iostream>
#include <climits>
using namespace std;

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

    cout << "--- Floyd-Warshall Algorithm ---" << endl;
    FloydWarshall(arr, n);

    return 0;
}
