class Solution {
public:
    // int dp[101][101];
    // int helper1(int i , int j ,int n ,vector<vector<int>>& matrix){
    //     if(j<0 || j>matrix[0].size()-1) return 1e9;
    //     if(i==0) return matrix[i][j];
    //     if(dp[i][j] != -1)return dp[i][j];
    //     int up =matrix[i][j] + helper1(i-1,j,n,matrix);
    //     int ld =matrix[i][j] + helper1(i-1,j-1,n,matrix);
    //     int rd =matrix[i][j] + helper1(i-1,j+1,n,matrix);
    //     return dp[i][j] = min({up,ld,rd});
        // }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int>prev(n,0);
        vector<int>curr(n,0);
        for(int j=0;j<n;j++) prev[j] = matrix[0][j];
        
        for(int i=1;i<n;i++){
            for(int j =0;j<n;j++){
                int up =matrix[i][j] + prev[j];
                
                int ld =matrix[i][j] ;
                if(j-1>=0) ld+= prev[j-1];
                else ld+= 1e9;

                int rd =matrix[i][j] ;
                if(j+1<n) rd+= prev[j+1];
                else rd+= 1e9;

                curr[j] = min({up,ld,rd});
            }
            prev= curr;
        }
        int ans = prev[0];
        for(int j = 1;j<n;j++){
            ans = min(ans, prev[j]);
        }

        return ans;
        
    }
};