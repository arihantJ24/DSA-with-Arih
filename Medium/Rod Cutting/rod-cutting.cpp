//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int f(int price[] , int n, int i,vector<vector<int>>&dp){
        
        if(i==0){
            return n*price[0];
        }
        
        if(dp[i][n]!=-1)return dp[i][n];
        int notpick = f(price,n,i-1,dp);
        int pick = INT_MIN;
        int rodlength = i+1;
        if(rodlength<=n){
            pick = price[i] + f(price,n-rodlength,i,dp);
        }
        return dp[i][n] = max(pick,notpick);
        
        
    }
    int cutRod(int price[], int n) {
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(price, n , n-1,dp);
        // for(int w = 1;w<=n;w++){
        //     dp[0][w] = (n/w) * price[0];
        // }
        // for(int i = 1;i<=n;i++){
        //     for(int j = 0 ;j<=n;j++){
        //         int notpick = dp[i-1][j];
        //         int pick = INT_MIN;
        //         int rodlength = i+1;
        //         if(rodlength<=n){
        //             pick = price[i] + dp[i][n-rodlength];
        //         }
        //         dp[i][j] = max(pick,notpick);
        //     }
        // }
        // return dp[n-1][n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends