class Solution {
public:
    bool solve(vector<int>&nums, int k , int index, vector<vector<int>>&dp){

        //base case 
        if(k== 0)return true;
        if(index == 0) return nums[0] == k ;
        if(dp[index][k] != -1) return dp[index][k];
        bool notTaken = solve(nums, k , index-1 , dp);
        bool Taken = false;
        if(nums[index]<= k) Taken = solve(nums,k-nums[index] , index-1 , dp);

        return dp[index][k] = Taken || notTaken ;
    }
    bool canPartition(vector<int>& nums) {
        int sum =0 ;
        int n = nums.size();
        for(auto & it: nums) sum+= it;

        if(sum %2 !=0) return false;

        int k = sum/2;

        vector<vector<int>>dp(201,vector<int>(k+1,-1));
        return solve(nums,k,n-1, dp);
    }
};