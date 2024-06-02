class Solution {
public:
    int f1(int idx, int buy, int n,int transactions, vector<int>& prices,vector<vector<vector<int>>>&dp){
        if(idx == n)return 0;
        if(transactions == 0)return 0;
        int profit = 0;
        if(dp[idx][buy][transactions] != -1)return dp[idx][buy][transactions];
        if(buy == 0) // we can buy the stock
        {
            // skip the transaction so variable buy == 0 reamins same means we purchase on next day and also transactions remain same as we didn't complete it.
            int op1 = 0 + f1(idx+1,0,n,transactions, prices,dp);
            // purchase the stock so variable  buy == 1  we purchase it today but transactions remain same as we didn't complete it.
            int op2 = -prices[idx] + f1(idx+1,1,n,transactions, prices,dp);
            profit = max(op1,op2);
        }
        else{
            // skip the sell so variable buy == 1 reamins same means we can make it to next day.
            int op1 = 0 + f1(idx+1,1,n,transactions, prices,dp);
            // sell the stock so variable  buy == 0 as we sell it and "transactions also decrement"  as we complete one transaction.
            int op2 = prices[idx] + f1(idx+1,0,n,transactions-1, prices,dp);
            profit =  max(op1,op2);
        }
        return dp[idx][buy][transactions] = profit ;
       
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        //------------------ memoization ----------------------------
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return f1(0,0,n,2,prices,dp);
    }
};