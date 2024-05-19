class Solution {
public:
    //M1-> memoization
    // int helper1(int i,  int j, vector<vector<int>>& triangle,int n,vector<vector<int>>& dp){
    //     //base case
    //     if(i == n-1) return triangle[n-1][j];
    //     if( dp[i][j] != -1)return  dp[i][j] ;
    //     // path
    //     int down = triangle[i][j] +helper1(i+1,j,triangle,n ,dp);
    //     int diagonal = triangle[i][j] + helper1(i+1,j+1,triangle,n ,dp);
    //     return dp[i][j] = min(down,diagonal);
    // }

    // int helper2(vector<vector<int>>& triangle,int n){
    //     int dp[n][n];
    //     for(int j = 0;  j<n ;j++){
    //         dp[n-1][j] = triangle[n-1][j];
    //     }
    //     for(int i = n-2;i>=0;i--){
    //         for(int j = i ;j>=0;j--){
    //             int down = triangle[i][j] + dp[i+1][j];
    //             int diagonal = triangle[i][j] + dp[i+1][j+1];
    //             dp[i][j] = min(down,diagonal);
    //         }
    //     }
    //     return dp[0][0];
    // }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        // vector<vector<int>>dp(n,vector<int>(n,-1));
        // return helper1(0,0,triangle,n,dp);

        // return helper2(triangle,n);

        // Space Optimisation
        

        vector<int>front(n);
        for(int j = 0;j<n;j++){
            front[j] = triangle[n-1][j];
        }

        for(int i= n-2;i>=0;i--){
            vector<int>curr(n);
            for(int j = i;j>=0;j--){
                int down = triangle[i][j] + front[j];
                int diagonal = triangle[i][j] + front[j+1];
                curr[j] = min(down,diagonal);
            }
            front = curr;
        }
        return front[0];
    }
};