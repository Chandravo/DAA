//This code is made by Chandravo Bhattacharya
#include<bits/stdc++.h>
using namespace std;
#define V 7

class node{
    public:
    bool known;
    int dist;
    int parent;
    node (){
        known = 0;
        dist = INT_MAX;
        parent = -1;
    }
};

int mindistnode(int adj[V][V], node T[V]){
    int res = -1;
    int minVal = INT_MAX;
    for (int i=0;i<V;i++){
        if (T[i].dist<minVal && (!T[i].known)) {
            res = i;
            minVal = T[i].dist;
        }
    }
    return res;
}

void dijkastra(int adj[V][V], int src){
    node T[V];
    T[src].dist = 0;
    T[src].known = 1;
    // int v = src;
    // for (int i=0;i<V;i++){
    //         if (adj[src][i]!=0){
    //             if (T[src].dist+adj[src][i]<T[i].dist){
    //                 T[i].dist = T[src].dist+adj[src][i];
    //                 T[i].parent = src;
    //             }
    //         }
    //     }
    int v = 0;
    for (;;){
        if (v==-1) break;
        T[v].known = 1;
        for (int i=0;i<V;i++){
            if (adj[v][i]!=0){
                // if (T[v].dist+adj[v][i]<T[i].dist){
                //     T[i].dist = T[v].dist+adj[v][i];
                //     T[i].parent = v;
                // }
                if (adj[v][i]<T[i].dist){
                    T[i].dist = adj[v][i];
                    T[i].parent = i;
                }
            }
        }
        v = mindistnode(adj, T);
    }
    for (int i=0;i<V;i++){
        cout<<T[i].dist<<" "<<T[i].parent+1<<endl;
    }
    return;

}



int main(){
    // int adj[7][7] = {
    //     {0, 2, 0, 1, 0, 0, 0},
    //     {0, 0, 0, 3, 10, 0, 0},
    //     {4, 0, 0, 0, 0, 5, 0},
    //     {0, 0, 2, 0, 2, 8, 4},
    //     {0, 0, 0, 0, 0, 0, 6},
    //     {0, 0, 0, 0, 0, 0, 0},
    //     {0, 0, 0, 0, 0, 1, 0}};

    // int adj[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
    //                     { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
    //                     { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
    //                     { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
    //                     { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
    //                     { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
    //                     { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
    //                     { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
    //                     { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
    int adj[7][7] = {
        {0, 2, 4, 1, 0, 0, 0},
        {2, 0, 0, 3, 10, 0, 0},
        {4, 0, 0, 2, 0, 5, 0},
        {1, 3, 2, 0, 7, 8, 4},
        {0, 10, 0, 7, 0, 0, 6},
        {0, 0, 5, 8, 0, 0, 1},
        {0, 0, 0, 4, 6, 1, 0}};
    

    dijkastra(adj, 0);
}