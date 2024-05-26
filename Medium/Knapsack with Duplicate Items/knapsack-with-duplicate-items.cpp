//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int f(int val[], int wt[], int i, int W, vector<vector<int>>&dp){
        if(i==0){
            return ((int)(W/wt[0])) * val[0];
            
        }
        if(dp[i][W] != -1)return dp[i][W];
        int notpick = f(val,wt , i-1,W,dp);
        int pick  = INT_MIN;
        if(wt[i]<=W) pick = val[i] + f(val , wt , i,W-wt[i],dp);
        
        return dp[i][W] = max(pick, notpick);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>>dp(N,vector<int>(W+1,-1));
        return f(val,wt,N-1,W,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends