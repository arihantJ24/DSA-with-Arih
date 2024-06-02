class Solution {
public:
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
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return f(0,0,n,prices,dp);
    }
};