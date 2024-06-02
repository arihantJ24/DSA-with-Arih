class Solution {
public:
    /* --------------------------------- Memoization -----------------------
    int f(int idx, int buy, int n,vector<int>& prices,vector<vector<int>>&dp ){
        if(idx >= n)return 0;// instead of idx == n we use idx>= n if this happen we return 0 as after selling we have a coodwom period of one day so we go to (idx+2)index;
        if(dp[idx][buy]!=-1)return dp[idx][buy];
        int profit = 0;

        if(buy ==0){
            return dp[idx][buy] = max(0+f(idx+1,0,n,prices,dp), - prices[idx]+f(idx+1,1,n,prices,dp));
        }
        else{
            return dp[idx][buy] = max(0+f(idx+1,1,n,prices,dp),prices[idx]+f(idx+2,0,n,prices,dp));
      
        }  
    }
    */

    int f2(vector<int>&prices){
        int n = prices.size();
        vector<vector<int>>dp(n+2,vector<int>(2,0));
        dp[n][0] = dp[n][1] = 0;
        
        for(int idx = n-1;idx>=0;idx--){
            for(int buy = 0;buy<=1;buy++){             
                if(buy ==0){
                    dp[idx][buy] = max(0+dp[idx+1][0], -prices[idx]+dp[idx+1][1] );
                }
                else{
                    dp[idx][buy] = max(0+dp[idx+1][1], prices[idx]+dp[idx+2][0] );
                }            
            }
        }
        return dp[0][0];
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        /* --------------------------------- Memoization -----------------------
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return f(0,0,n,prices,dp);
        */
        // --------------------------------- Tabulation -----------------------
        return f2(prices);
        
    }
};