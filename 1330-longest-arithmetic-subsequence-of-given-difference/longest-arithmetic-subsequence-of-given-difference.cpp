class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int>dp;
        int maxlength =0;
        for(int x : arr){
            if(dp.find(x- difference) != dp.end()){
                dp[x] = 1 + dp[x-difference];
            }
            else 
            dp[x] = 1;

            maxlength = max(maxlength , dp[x]);
        }
        return maxlength;
    }
};