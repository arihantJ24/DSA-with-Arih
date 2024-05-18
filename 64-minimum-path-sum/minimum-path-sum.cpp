class Solution {
public:

    // M1-> memoization
    // int helper1(int  i , int j , vector<vector<int>>& grid,vector<vector<int>>&dp){
    //     if(i<0 || j<0)return 1e9;
    //     if(i== 0 && j== 0)return grid[i][j];
    //     if(dp[i][j]!= -1)return dp[i][j];
        
    //     int up = helper1(i-1,j,grid,dp) + grid[i][j];

    //     int down = helper1(i,j-1,grid,dp) + grid[i][j];

    //     return dp[i][j] = min(up,down);
    // }

    //M2 Tabulation
    // int helper2(int m , int n,vector<vector<int>>& grid){
    //     int dp[m][n];
    //     for(int i = 0 ;i<m;i++){
    //         for(int j = 0 ;j<n;j++){
    //             if(i == 0 && j == 0)dp[i][j] = grid[i][j];
    //             else{
    //                 int up=grid[i][j] ,left =grid[i][j];
    //                 if(i>0)up +=dp[i-1][j];
    //                 else up += 1e9;

    //                 if(j>0)left += dp[i][j-1];
    //                 else left += 1e9;
    //                 dp[i][j]= min(up,left) ;
    //             }
    //         }
    //     }
    //     return dp[m-1][n-1];
    // }

    // M3 - Space Optimisation

    int helper3(int m , int n,vector<vector<int>>& grid){
        int dp[m][n];
        vector<int>prev(n,0);
        for(int i = 0 ;i<m;i++){
            vector<int>curr(n,0);
            for(int j = 0 ;j<n;j++){
                if(i == 0 && j == 0)curr[j] = grid[i][j];
                else{

                    int up=grid[i][j],left =grid[i][j];

                    if(i>0)up +=prev[j];
                    else up += 1e9;

                    if(j>0)left += curr[j-1];
                    else left += 1e9;

                    curr[j]= min(up,left) ;
                }
            }
            prev = curr;
        }
        return prev[n-1];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // vector<vector<int>>dp(m,vector<int>(n,-1));
        // return helper1(m-1,n-1, grid,dp);
        // return helper2(m,n, grid);

        return helper3(m,n, grid);
    }
};