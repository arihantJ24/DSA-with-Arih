class Solution {
public:
    int minInsertions(string s) {
        string t = s;
        reverse(t.begin(),t.end());
        // by this we find the longest palindromic subsequence
        int n =s.length();
        // -------------------- Tabulation ----------
        // vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        // for(int i = 1;i<=n;i++){
        //     for(int j =1;j<=n;j++){
        //         if(s[i-1] == t[j-1])dp[i][j] = 1+ dp[i-1][j-1];
        //         else dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
        //     }
        // }

        // ---------------- Space optimise -----------
        
        vector<int>prev(n+1,0),curr(n+1,0);
        for(int i = 1;i<=n;i++){
            for(int j =1;j<=n;j++){
                if(s[i-1] == t[j-1])curr[j] = 1+ prev[j-1];
                else curr[j] = max(curr[j-1],prev[j]);
            }
            prev = curr;
        }

        /* by this we find the longest subsequence and we have to return minimum 
        step to make whole string palindrome so just "subtract the total length - longest"
        */
        return n - prev[n];

    }
};