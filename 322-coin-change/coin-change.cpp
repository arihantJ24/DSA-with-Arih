class Solution {
public:
    int f(int i, int k,vector<int>& coins,vector<vector<int>>&dp){
        if(i==0){
            if((k % coins[0]) == 0) return k/coins[0];
            return 1e9;
        }
        if(dp[i][k]!= -1)return dp[i][k];
        int notpick = 0 + f(i-1,k,coins,dp);
        int pick = 1e9;
        if(coins[i]<= k){
            pick = 1 + f(i, k - coins[i],coins,dp);
        }
        return dp[i][k] = min(pick , notpick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        
        return (f(n-1,amount,coins,dp) == 1e9) ? -1 : f(n-1,amount,coins,dp) ;
    }
};