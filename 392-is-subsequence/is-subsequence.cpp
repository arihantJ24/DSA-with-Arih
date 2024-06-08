class Solution {
public:
    int solve(string &s, string &t , int i , int j ,vector<vector<int>>&dp){
        if(i==0 || j==0)return 0;
        if(dp[i][j]!= -1)return dp[i][j];
        if(s[i-1] == t[j-1]) return dp[i][j] = 1+ solve(s,t,i-1,j-1,dp);
        else return dp[i][j] = solve(s,t,i,j-1,dp);
    }
    bool isSubsequence(string s, string t) {
        int n = s.length();
        int m = t.length();
        if(n>m) return false;

        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        if(solve(s,t,n,m,dp) == n) return true;
        return false;

    }
};