class Solution {
public:
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
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return f(0,0,k,n,prices,dp);
    }
};