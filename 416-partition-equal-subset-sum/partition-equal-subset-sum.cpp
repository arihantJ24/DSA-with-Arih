class Solution {
public:
    // Memoization 
    // bool solve(vector<int>&nums, int k , int index, vector<vector<int>>&dp){

    //     //base case 
    //     if(k== 0)return true;
    //     if(index == 0) return nums[0] == k ;
    //     if(dp[index][k] != -1) return dp[index][k];
    //     bool notTaken = solve(nums, k , index-1 , dp);
    //     bool Taken = false;
    //     if(nums[index]<= k) Taken = solve(nums,k-nums[index] , index-1 , dp);

    //     return dp[index][k] = Taken || notTaken ;
    // }

    bool canPartition(vector<int>& nums) {
        int sum =0 ;
        int n = nums.size();
        for(auto & it: nums) sum+= it;
        if(sum %2 !=0) return false;
        int k = sum/2;
        vector<vector<bool>>dp(201,vector<bool>(k+1,false));

        for(int i =0;i<n;i++){
            dp[i][0] =true;
        }
        if(nums[0]<= k){
            dp[0][nums[0]] = true;
        }

        for(int idx =1 ;idx<n;idx++){
            for(int target = 1;target <=k;target++){
                bool notTaken = dp[idx-1][target];
                bool taken = false;
                if(nums[idx]<=target){
                    taken = dp[idx-1][target- nums[idx]];
                }
                dp[idx][target] = taken || notTaken;
            }
        }
        return dp[n-1][k];
    }
};