//This code is made by Chandravo Bhattacharya
#include<bits/stdc++.h>
using namespace std;



void print(int arr[], int n){
    for (int i=0;i<n;i++){
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}

bool isSafe(int result[], int x, int y){
    for (int i=0;i<x;i++){
        if (result[i]==y || (abs(result[i]-y)==abs((i-x)))) return 0;
    }
    return 1;
}

void nqueen(int result[], int x, int n){
    // cout<<"now at "<<x<<endl;
    for (int i=0;i<n;i++){
        if (isSafe(result, x, i)){
            result[x] = i;

            if (x==n-1){
                print(result, n);
                return;
            }

            nqueen(result,x+1,n);
        }

    }
}

bool issafe(int res[],int x2,int y2){
    for(int i=0;i<x2;i++){
        if(res[i] == y2 || abs(i-x2)==abs(res[i]-y2))
            return 0;
    }
    return 1;
}
void placeQueens(int res[],int x,int size){
    for(int i=0;i<size;i++){
        if(issafe(res,x,i)){
            res[x] = i;
            if(x == size-1){
                print(res,size);
                return;
            }
            placeQueens(res,x+1,size);
        }
    }
}

int main(){
    int n;cin>>n;
    int result[n];
    nqueen(result, 0, n);
}