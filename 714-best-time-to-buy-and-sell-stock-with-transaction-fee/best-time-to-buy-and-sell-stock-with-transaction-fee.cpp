class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        // -------------------- Tabulation --------------------------
        /* vector<vector<int>>dp(n+1,vector<int>(2,0));
        for(int i = n-1;i>=0;i--){
            // buy == 0 means we can purchase here,have two option take max of it
            dp[i][0] = max(0+dp[i+1][0] , -prices[i]+dp[i+1][1]);
            // buy == 1 means we can sell here,have two option take max of it here when we sell then apply the fee
            dp[i][1] = max(0+dp[i+1][1] , prices[i] - fee +dp[i+1][0]);
        }
        return dp[0][0];
        */
        // -------------------- Space Optimised --------------------------
        vector<int>dp(2,0);
        for(int i = n-1;i>=0;i--){
            dp[0] = max(0+dp[0] , -prices[i]+dp[1]);   
            dp[1] = max(0+dp[1] , prices[i] - fee +dp[0]);
        }
        return dp[0];

    }
};