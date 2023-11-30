// This code is made by Lovedeep singh
#include <bits/stdc++.h>
using namespace std;
class nodes
{

public:
    int known;
    int dist;
    int parent;
    nodes()
    {
        known = 0;
        dist = INT_MAX;
        parent = -1;
    }
};
void shortestpath()
{
    int n = 0;
    int adj[7][7] = {
        {0, 2, 4, 1, 0, 0, 0},
        {2, 0, 0, 3, 10, 0, 0},
        {4, 0, 0, 2, 0, 5, 0},
        {1, 3, 2, 0, 7, 8, 4},
        {0, 10, 0, 7, 0, 0, 6},
        {0, 0, 5, 8, 0, 0, 1},
        {0, 0, 0, 4, 6, 1, 0}};
    nodes v[7];
    v[n].dist = 0;
    for (int j = 0; j < 7; j++)
    {
        v[n].known = 1;

        for (int i = 0; i < 7; i++)
        {
            if (adj[n][i] != 0)
            {
                if(v[i].dist<adj[n][i])
                {
                continue;
                }
                else{
                v[i].dist = adj[n][i];
                v[i].parent = n;
                
                }
            }
        }

        int m = INT_MAX;
        for (int i = 0; i < 7; i++)
        {
            if (m > v[i].dist && v[i].known == 0)
            {
                m = v[i].dist;
                n = i;
            }
        }
    }
    for (int i = 0; i < 7; i++)
    {
        cout << i + 1 << " " << v[i].known << " " << v[i].dist << " " << v[i].parent+1 << endl;
    }
}

int main()
{

    shortestpath();
}


// #include <iostream>
// #include <climits>
// #define V 7
// using namespace std;

// int minKey(int key[], bool mstSet[]) {
//     int min = INT_MAX, min_index;
//     for (int v = 0; v < V; v++)
//         if (mstSet[v] == false && key[v] < min)
//             min = key[v], min_index = v;
//     return min_index;
// }

// void printMST(int parent[], int graph[V][V]) {
//     cout<<"Edge \tWeight\n";
//     for (int i = 1; i < V; i++)
//         cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n";
// }

// void primMST(int graph[V][V]) {
//     int parent[V];
//     int key[V];
//     bool mstSet[V];
//     for (int i = 0; i < V; i++)
//         key[i] = INT_MAX, mstSet[i] = false;
//     key[0] = 0;
//     parent[0] = -1;
//     for (int count = 0; count < V - 1; count++) {
//         int u = minKey(key, mstSet);
//         mstSet[u] = true;
//         for (int v = 0; v < V; v++)
//             if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
//                 parent[v] = u, key[v] = graph[u][v];
//     }
//     printMST(parent, graph);
// }

// int main() {
//     int adj[7][7] = {
//         {0, 2, 0, 1, 0, 0, 0},
//         {0, 0, 0, 3, 10, 0, 0},
//         {4, 0, 0, 0, 0, 5, 0},
//         {0, 0, 2, 0, 2, 8, 4},
//         {0, 0, 0, 0, 0, 0, 6},
//         {0, 0, 0, 0, 0, 0, 0},
//         {0, 0, 0, 0, 0, 1, 0}};
//     primMST(adj);
//     return 0;
// }