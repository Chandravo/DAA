//This code is made by Chandravo Bhattacharya
#include<bits/stdc++.h>
using namespace std;
#define n 5

void print(int res[n][n]){
    for (int i=0;i<n;i++){
        for (int j = 0;j<n;j++){
            cout<<res[i][j]<<"\t";
        }
        cout<<endl;
    }
}

void floydwarshall(int adj[n][n]){
    for (int i=0;i<n;i++){
        adj[i][i] = 0;
    }
    int res[n][n];
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (adj[i][j]==0 && i!=j){
                res[i][j] = 100000;
            }
            else res[i][j] = adj[i][j];
        }
    }
    print(res);
    for (int k=0;k<n;k++){
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                if (res[i][k]+res[k][j]<res[i][j]){
                    res[i][j] = res[i][k]+res[k][j];
                }
            }
        }
    }
    cout<<endl;
    print(res);
    
}

int main(){
    int adj[5][5] = {
        {0,2,3,0,0},
        {2,0,1,0,5},
        {3,0,0,1,0},
        {1,0,0,0,2},
        {0,0,3,0,0}
    };
    // int adj[4][4] = {
    //     {7,5,0,0},
    //     {7,0,0,2},
    //     {0,3,0,0},
    //     {4,0,1,0},
    // };
    floydwarshall(adj);
    
}