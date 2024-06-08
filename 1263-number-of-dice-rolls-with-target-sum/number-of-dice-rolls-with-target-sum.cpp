class Solution {
public:
    const int mod = 1e9+7;
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1,vector<int>(target+1));
        dp[0][0] =1;
        for(int dice = 1;dice<=n;dice++){
            for(int currTarget = 1;currTarget <= target;currTarget++){
                for(int face =1 ;face<=k;face++){
                    if(currTarget>=face){
                        dp[dice][currTarget] =( dp[dice][currTarget] + 
                        dp[dice-1][currTarget-face]) % mod;
                    }
                }
            }
        }
        return dp[n][target];
    }
};