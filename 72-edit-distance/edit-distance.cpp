class Solution {
public:
    /* int f(string & word1, string & word2 , int i , int j ,vector<vector<int>>&dp){
        if(i == 0){
            return j; // word1 is exhausted so we print the count of string 2 that is left
        }
        if(j == 0){
            return i; // word2 is exhausted so we print the count of string 1 that is left
        }
        if(dp[i][j]!= -1)return dp[i][j];

        if(word1[i-1]== word2[j-1]) return dp[i][j] = 0+ f(word1,word2, i-1 , j-1,dp);
        return dp[i][j] = 1+ min({ f(word1,word2, i-1 , j-1,dp),f(word1,word2, i , j-1,dp),f(word1,word2, i-1 , j,dp)});

    } */
    int minDistance(string word1, string word2) {
        int n = word1.length() , m = word2.length();
        
        // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        // return f(word1, word2, n, m, dp);

        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        for(int i =0 ;i<=n;i++){
            dp[i][0] = i;
        }

        for(int j = 0 ;j<=m;j++){
            dp[0][j] = j;
        }

        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                if(word1[i-1]== word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 1+ min({ dp[i-1][j-1] , dp[i][j-1], dp[i-1][j]});
                }
            }
        }
        return dp[n][m];
        

    }
};