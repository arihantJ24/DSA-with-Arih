class Solution {
public:
    int solve(int idx ,int rem ,vector<int>&nums, vector<vector<int>>&dp){
        
        if(idx<0){
            return rem == 0 ? 0 : -1e9;
        }
        if(dp[idx][rem]!= -1)return dp[idx][rem];
        int notpick = 0+ solve(idx-1,rem,nums,dp);
        int pick = nums[idx]+ solve(idx-1,(nums[idx]+rem)%3,nums,dp);
        return dp[idx][rem] =  max(pick,notpick);
    }
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(4,-1));
        return solve(n-1,0,nums,dp);
    }
};