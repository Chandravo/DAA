//This code is made by Chandravo Bhattacharya
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> p{15,10,9,5};
    vector<int> w{1,5,3,4};
    int W = 8;
    vector<vector<int>> dp(4+1, vector<int> (8+1));
    for (int i=0;i<=4;i++){
        for (int j = 0;j<=8;j++){
            if (i==0 || j==0){
                dp[i][j] = 0;
                continue;
            }
            if (w[i-1]<=j) dp[i][j] = max(p[i-1]+dp[i-1][j-w[i-1]], dp[i-1][j]);
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout<<dp[4][W];
}