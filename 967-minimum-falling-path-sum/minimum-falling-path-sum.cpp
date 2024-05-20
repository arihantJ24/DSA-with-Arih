class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int dp[101][101];

        for(int j = 0;j<n;j++){
            dp[0][j] = matrix[0][j];
        }

        for(int i = 1;i<n;i++){
            for(int j =0 ;j<n;j++){
                int up = matrix[i][j] + dp[i-1][j];

                int ld = matrix[i][j];
                if(j-1>=0) ld += dp[i-1][j-1];
                else ld += 1e9;
                int rd = matrix[i][j];
                if(j+1< n) rd += dp[i-1][j+1];
                else rd += 1e9;

                dp[i][j] = min({up, ld,rd});
            }
        }

        int ans = 1e9;
        for(int j =0;j<n;j++){
            ans = min(ans,dp[n-1][j]);
        }
        return ans;
    }
};