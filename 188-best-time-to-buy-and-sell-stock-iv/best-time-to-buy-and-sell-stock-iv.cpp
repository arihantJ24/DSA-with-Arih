class Solution {
public:
    /* ------------------------------------- Memoization----------------------------
    int f(int idx, int buy, int k ,int n,vector<int>& prices , vector<vector<vector<int>>>&dp){
        if(idx == n || k ==0) return 0;
        if(dp[idx][buy][k] != -1)return dp[idx][buy][k];
        int profit = 0;
        if(buy == 0){
            profit =max(0+f(idx+1,0,k,n,prices,dp), -prices[idx]+f(idx+1,1,k,n,prices,dp));
        }
        else{
            profit =max(0+f(idx+1,1,k,n,prices,dp), prices[idx]+f(idx+1,0,k-1,n,prices,dp));
        }
        return dp[idx][buy][k] = profit;
    } */

    /* ++++++++++++++++++++++++++++++++ Tabulation ++++++++++++++++++++++++++++
    int f2(int idx, int buy, int k ,int n,vector<int>& prices , vector<vector<vector<int>>>&dp){
        // here actually it is not neccessary to write a base case as we initialising the all value to 0 still we writing it
        // for(int idx= 0;idx<=n;idx++){
        //     for(int buy = 0 ;buy<=1;buy++){
        //         dp[idx][buy][0] =0; // if k=0 then any idx and buy = 0;
        //     }
        // }
        // for(int buy= 0;buy<=1;buy++){
        //     for(int j = 0 ;j<=k;j++){
        //         dp[n][buy][j] =0; // if idx = n then any k and buy = 0;
        //     }
        // }

        for(int idx = n-1; idx >= 0;idx--){
            for(int buy =0;buy<=1;buy++){
                for(int cap = 1;cap<=k;cap++){
                    int profit = 0;
                    if(buy == 0){
                        profit =max(0+dp[idx+1][0][cap], -prices[idx]+dp[idx+1][1][cap]);
                    }
                    else{
                        profit =max(0+dp[idx+1][1][cap], prices[idx]+dp[idx+1][0][cap-1] );
                    }
                    dp[idx][buy][cap] =  profit;
                }
            }
        }
        return dp[0][0][k];
    } */

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        // ------------------------------ Memoization----------------------------
        // vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        // return f(0,0,k,n,prices,dp);

        //++++++++++++++++++++++++++++++++ Tabulation ++++++++++++++++++++++++++++
        // vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        // return f2(0,0,k,n,prices,dp);

        //============================= Method 2 ==================
        // DP[n][k]; -------------- Tabulation -----------------
        // vector<vector<int>>dp(n+1,vector<int>(2*k+1,0));

        // for(int i =n-1;i>=0;i--){
        //     for(int cap = 2*k -1 ;cap>= 0;cap--){
        //         if(cap%2 == 0){
        //             dp[i][cap] = max(-prices[i]+dp[i+1][cap+1] ,0+ dp[i+1][cap]);
        //         }
        //         else{
        //             dp[i][cap] = max(prices[i]+dp[i+1][cap+1] ,0+ dp[i+1][cap]);
        //         }
        //     }
        // }
        // return dp[0][0];

        //============================= Method 2 ==================
        // ------------------------ space optimisation -------------
        vector<int>after(2*k+1,0);
        vector<int>curr(2*k+1,0);
        for(int i =n-1;i>=0;i--){
            for(int cap = 2*k -1 ;cap>= 0;cap--){
                if(cap%2 == 0){
                    curr[cap] = max(-prices[i]+after[cap+1] ,0+ after[cap]);
                }
                else{
                    curr[cap] = max(prices[i]+after[cap+1] ,0+ after[cap]);
                }
            }
            after = curr;
        }
        return after[0];

    }
};