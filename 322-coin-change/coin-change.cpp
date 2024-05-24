class Solution {
public:
    // int f(int i, int k,vector<int>& coins,vector<vector<int>>&dp){
    //     if(i==0){
    //         if((k % coins[0]) == 0) return k/coins[0];
    //         return 1e9;
    //     }
    //     if(dp[i][k]!= -1)return dp[i][k];
    //     int notpick = 0 + f(i-1,k,coins,dp);
    //     int pick = 1e9;
    //     if(coins[i]<= k){
    //         pick = 1 + f(i, k - coins[i],coins,dp);
    //     }
    //     return dp[i][k] = min(pick , notpick);
    // }

    int f2(int i, int k,vector<int>& coins,vector<vector<int>>&dp){
        int n = coins.size();
        for(int amt = 0;amt<=k;amt++){
            if(k%coins[amt] == 0)dp[0][amt] = k/coins[amt];
            else dp[0][amt]= 1e9;
        }

        for(int i = 1;i<n;i++){
            for(int amt = 0;amt<=k;amt++){
                int notpick = 0 + dp[i-1][amt];
                int pick = 1e9;
                if(coins[i]<= amt)
                    pick = 1 +  dp[i-1][amt - coins[i]];
                dp[i][amt] = min(pick,notpick);
            }
        }

        return (dp[n-1][k] == 1e9) ? -1 : dp[n-1][k];
    }
    int coinChange(vector<int>& coins, int k) {
        int n = coins.size();
        
        // vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        // return (f(n-1,amount,coins,dp) == 1e9) ? -1 : f(n-1,amount,coins,dp) ;

        vector<vector<int>>dp(n,vector<int>(k+1,0));

        for(int amt = 0;amt<=k;amt++){
            if(amt%coins[0] == 0)dp[0][amt] = amt/coins[0];
            else dp[0][amt]= 1e9;
        }

        for(int i = 1;i<n;i++){
            for(int amt = 0;amt<=k;amt++){
                int notpick = 0 + dp[i-1][amt];
                int pick = 1e9;
                if(coins[i]<= amt)
                    pick = 1 +  dp[i][amt - coins[i]];

                dp[i][amt] = min(pick,notpick);
            }
        }
        return (dp[n-1][k] == 1e9) ? -1 : dp[n-1][k];
    }
};