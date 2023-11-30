//This code is made by Chandravo Bhattacharya
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> cn{10,6,1};
    int a = 12;
    int n = 3;
    vector<vector<int>> dp(4, vector<int> (a+1));
    for (int i=0;i<=a;i++) dp[0][i] = INT_MAX-1;
    for (int i=0;i<=n;i++) dp[i][0] = 0;

    for (int i=1;i<=n;i++){
        for (int j = 1;j<=a;j++){
            if (cn[i-1]<=j){
                dp[i][j] = min(1+dp[i][j-cn[i-1]], dp[i-1][j]);
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout<< dp[n][a];    
    
}