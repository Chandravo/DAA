//This code is made by Chandravo Bhattacharya
#include<bits/stdc++.h>
using namespace std;
#define n 4


void print(int arr[], int m){
    for (int i=0;i<n;i++){
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}

bool isSafe(int k, int c, int adj[n][n], int res[]){
    for (int i=0;i<n;i++){
        if (adj[k][i]!=0 && res[i]==c) return 0;
    }
    return 1;
}

void colorgraph(int adj[n][n],int k, int m, int res[n]){
    for (int c = 1;c<=m;c++){
        if (isSafe(k,c, adj, res)){
            res[k]=c;
            if (k==n-1){
                print(res,n);
                exit(0);
            }
            colorgraph(adj, k+1,m,res);
        }
    }
}

int main(){
    int adj[n][n] ={
        {0,1,0,1},
        {1,0,1,1},
        {0,1,0,1},
        {1,1,1,0}
    };
    int res[n];
    colorgraph(adj, 0,n,res);
}