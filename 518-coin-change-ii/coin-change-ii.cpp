class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // vector<vector<int>>dp(n,vector<int>(amount+1,0));
        vector<int>prev(amount+1,0),curr(amount+1,0);
        for(int target = 0;target<= amount;target++){
            if(target% coins[0] ==0)prev[target] = 1;
            else prev[target] =0;
        }

        for(int i = 1;i<n;i++){
            for(int j = 0;j<=amount;j++){
                int nottake = prev[j];
                int take = 0;
                if(coins[i]<=j){
                    take = curr[j-coins[i]];
                }
                curr[j] = take + nottake;
            }
            prev = curr;
        }
        return prev[amount];
    }
};