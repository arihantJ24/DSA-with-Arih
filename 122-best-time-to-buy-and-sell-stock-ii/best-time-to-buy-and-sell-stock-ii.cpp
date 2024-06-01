class Solution {
public:
    int f(int idx,int buy,vector<int>& prices,int n,vector<vector<int>>&dp){
        if(idx ==n){
            return 0;
        }
        if(dp[idx][buy]!=-1)return dp[idx][buy];
        int profit =0;
        if(buy==0) // this mean he buy today now have to option
        {
            int op1 = -prices[idx] + f(idx+1,1,prices,n,dp);
            int op2 = 0 + f(idx+1,0,prices,n,dp);
            profit = max(op1,op2); 
        }
        else{
            int op1 = prices[idx] + f(idx+1,0,prices,n,dp);
            int op2 = 0 + f(idx+1,1,prices,n,dp);
            profit = max(op1,op2); 
        }
        return dp[idx][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));

        return f(0,0,prices,n, dp);
    }
};