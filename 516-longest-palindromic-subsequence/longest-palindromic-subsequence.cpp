class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(),t.end());
        int n = s.length();
        
        // vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        // for(int i = 1;i<=n;i++){
        //     for(int j= 1;j<=n;j++){
        //         if(s[i-1]== t[j-1]){
        //             dp[i][j] = 1+dp[i-1][j-1];
        //         }
        //         else{
        //             dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
        //         }
        //     }
        // }
        // return dp[n][n];  

        // Optimised
        vector<int>prev(n+1,0),curr(n+1,0);
        for(int i = 1;i<=n;i++){
            for(int j= 1;j<=n;j++){
                if(s[i-1]== t[j-1]){
                    curr[j] = 1+prev[j-1];
                }
                else{
                   curr[j] = max(curr[j-1],prev[j]);
                }
            }
            prev = curr;
        }
        return prev[n];  
    }


};