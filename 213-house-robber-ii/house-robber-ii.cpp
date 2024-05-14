class Solution {
public:
    int solve(vector<int>&arr){
        int n = arr.size();

        vector<int>dp(n,0);
        int prev1 = arr[0];
        int prev2 = 0;

        for(int i = 1 ; i<n ;i++){
            int pick = arr[i];
            if(i>1)pick+= prev2;
            int notpick = 0+ prev1;

            int curri = max(pick,notpick);
            prev2= prev1;
            prev1 = curri;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
        vector<int>arr1,arr2;
        for(int i =0 ; i< n;i++){
            if(i!=0)arr1.push_back(nums[i]);
            if(i!= n-1)arr2.push_back(nums[i]);    
        }
        int ans1 = solve(arr1);
        int ans2 = solve(arr2);
        return max(ans1,ans2);
    }
};