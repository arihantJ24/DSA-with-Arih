class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n =nums.size();
        vector<int>arr(10000+1,0);
        vector<int>dp(10000+1,0);
        for(int i = 0;i<n;i++){
            arr[nums[i]] += nums[i]; 
        }
        dp[0] =arr[0];
        dp[1] = max(arr[0],arr[1]);
        for(int i = 2;i<10001;i++){
            int notpick = dp[i-1];
            int pick = arr[i] + dp[i-2];
            dp[i] = max(pick,notpick );
        }
        return dp[10000];
    }
};