class Solution {
public:
    // method1 -> memoization
    // int helper1(int i , int j , vector<vector<int>>&dp){
    //     if(i== 0 && j==0 ) return 1;
    //     if(i<0 || j<0) return 0;
    //     if(dp[i][j] != -1)return dp[i][j];
    //     int up = helper1(i-1,j, dp);
    //     int left = helper1(i,j-1, dp);
    //     return dp[i][j]= up+left;
    // }

    // method 2 -> tabulation

    int helper2(int m , int n){
        int dp[m][n];
        for(int i = 0 ;i<m;i++){
            for(int j = 0 ;j<n;j++){
                if(i == 0 && j== 0)dp[i][j] = 1;
                else{
                    int up = 0, down =0;
                    if(i>0)up = dp[i-1][j];
                    if(j>0)down = dp[i][j-1];
                    dp[i][j] = up+down;
                }
            }
        }
        return dp[m-1][n-1];
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n,0));
        // return helper1(m-1, n-1,  dp);
        return helper2(m, n);
    }
};