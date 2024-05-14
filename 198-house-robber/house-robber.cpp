class Solution {
public:
    // int f(vector<int>&nums, int ind, vector<int>&dp){
    //     if(ind == 0)return nums[ind];
    //     if(ind<0)return 0;
    //     if(dp[ind]!= -1)return dp[ind];
    //     int pick = nums[ind]+ f(nums, ind-2, dp);
    //     int notpick = 0+ f(nums, ind-1, dp);

    //     return dp[ind] = max(pick ,notpick);
    // }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,0);
        int prev1 = nums[0];
        int prev2 = 0;
        for(int i = 1 ;i<n ;i++){
            int pick = nums[i];
            if (i>1)pick+= prev2;
            int notpick =0 +prev1;

            int curri= max(pick, notpick);

            prev2 = prev1;
            prev1= curri;
        }
        return prev1;
    }
};