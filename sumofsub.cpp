//This code is made by Chandravo Bhattacharya
#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int p, int r){
  int i = p - 1;
  for(int j=p; j<r; j++){
    if(arr[j] < arr[r]){
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i+1], arr[r]);
  return i+1;
}

void quickSort(int arr[], int p, int r){
  if(p < r){
    int q = partition(arr, p, r);
    quickSort(arr, p, q-1);
    quickSort(arr, q+1, r);
  }
}

void sumofsub(int s, int k, int r, int res[],int arr[], int m, int n){
    res[k] = 1;
    if (s+arr[k]==m){
        for (int i=0;i<n;i++){
            cout<<res[i]<<"\t";
        }
        cout<<endl;
        return;
    }
    if (s+arr[k]+arr[k+1]<=m) sumofsub(s+arr[k],k+1,r-arr[k],res,arr,m,n);

    if (s+r-arr[k]>=m && s+arr[k+1]<=m) {
        res[k]=0;
        sumofsub(s,k+1,r-arr[k],res,arr,m,n);
    }
}

int main(){
    int arr[] = {7,11,13,24};
    int m = 31;
    int n = 4;
    // sort(arr, arr+n);
    int total = accumulate(arr,arr+n,0);
    int res[n]={0};
    sumofsub(0,0,total,res,arr,m,n);
}