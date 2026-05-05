#include <bits/stdc++.h>              
using namespace std;                  


struct Edge {
    int u;                           
    int v;                            
    int w;                           
};


class DSU {
    vector<int> parent;               
    vector<int> rank;                 

public:
    DSU(int n) {                      
        parent.resize(n + 1);         
        rank.resize(n + 1, 0);        
        for (int i = 1; i <= n; i++)
            parent[i] = i;           
    }

    int find(int x) {                 
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int a, int b) {         
        a = find(a);                  
        b = find(b);                  
        if (a == b) return false;     

        if (rank[a] < rank[b])
            parent[a] = b;
        else if (rank[a] > rank[b])
            parent[b] = a;
        else {
            parent[b] = a;
            rank[a]++;
        }
        return true;
    }
};

int main() {
    const int V = 8;                 
    const int INF = 0;               


    int graph[V + 1][V + 1] = {
        {0},
        {0, 0, 0, 47, 0, 80, 54, 0, 0},   
        {0, 0, 0, 55, 31, 32, 0, 74, 79}, 
        {0, 47, 55, 0, 88, 23, 75, 66, 0},
        {0, 0, 31, 88, 0, 0, 74, 0, 29},  
        {0, 80, 32, 23, 0, 0, 0, 93, 0},  
        {0, 54, 0, 75, 74, 0, 0, 0, 0},   
        {0, 0, 74, 66, 0, 93, 0, 0, 68}, 
        {0, 0, 79, 0, 29, 0, 0, 68, 0}    
    };

    vector<Edge> edges;              


    for (int i = 1; i <= V; i++) {
        for (int j = i + 1; j <= V; j++) {
            if (graph[i][j] != INF) {
                edges.push_back({i, j, graph[i][j]});
            }
        }
    }

  
    sort(edges.begin(), edges.end(),
         [](Edge a, Edge b) {
             return a.w < b.w;
         });

    DSU dsu(V);                       
    int mstWeight = 0;                

    cout << "Edges in the MST:\n";

    // Kruskal’s Algorithm
    for (Edge e : edges) {
        if (dsu.unite(e.u, e.v)) {    
            cout << e.u << " - " << e.v
                 << " : " << e.w << endl;
            mstWeight += e.w;         
        }
    }

    cout << "Total MST weight = "
         << mstWeight << endl;

    return 0;                         
}
