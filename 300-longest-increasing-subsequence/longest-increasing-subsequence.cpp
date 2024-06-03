class Solution {
public:
    /* ---------------------------------- Memozation -------------------------------
    int f(int idx, int prev_idx ,int n, vector<int>& nums,vector<vector<int>>&dp){
        if(idx == n)return 0;
        if(dp[idx][prev_idx+1] !=-1) return dp[idx][prev_idx+1];

        //notpick
        int notpick = 0+f(idx+1,prev_idx,n,nums,dp);
        int pick = -1e9;
        if(prev_idx== -1 || nums[idx]>nums[prev_idx]){
            pick = 1+f(idx+1,idx,n,nums,dp);
        }
        return dp[idx][prev_idx+1] = max(pick,notpick); 
    }*/

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // vector<vector<int>>dp(n,vector<int>(n+1,-1));
        // return f(0,-1,n,nums,dp);

        /* --------------------------------------- Tabulation 1--------------------------------
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int idx= n-1;idx>=0;idx--){
            for(int prev_idx = idx-1 ;prev_idx >= -1;prev_idx--){
                int len = 0+dp[idx+1][prev_idx+1]; //prev_idx is incremented because of cordinate shift
                if(prev_idx == -1 || nums[idx]>nums[prev_idx]){
                    len = max(len,1+dp[idx+1][idx+1]);// if we take it then update it
                }

                dp[idx][prev_idx+1]  = len;
            }
        }
        return dp[0][-1+1];

        */

        /* ---------------------------- Tabulation 2 t.c = 0(N^2) s.c = 0(N)-------------------------------
        vector<int>dp(n,1);
        for(int i = 0;i<n;i++){
            for(int prevIdx = 0; prevIdx<= i-1; prevIdx++){
                if(nums[prevIdx]<nums[i]){
                    dp[i] = max(dp[i], 1+dp[prevIdx]);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
        */

        // ---------------------------- Binary Search----------------
        vector<int>temp;
        temp.push_back(nums[0]);
        int len = 1;
        for(int i = 1;i<n;i++){
            if(nums[i]>temp.back()){
                temp.push_back(nums[i]);
                len++;
            }
            else{
                int ind = lower_bound(temp.begin(),temp.end(), nums[i])-temp.begin();
                temp[ind] =nums[i];
            }
        }
        return len;

    }
};