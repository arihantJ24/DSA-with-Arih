class Solution {
public:
    int minDistance(string word1, string word2) {
        /* so  what we can do here is we first find the LCS of both the string so we get
        to know what is the common between both of them then we just simply subtract the length 
        of LCS with length of word1 and word2.*/

        int n= word1.size();
        int m = word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i =1;i<=n;i++){
            for(int j =1;j<=m;j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = 1+ dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max( dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        // so this store length of longest common subsequnce at dp[n][m];
        int length = dp[n][m];
        return (n-length)+(m-length);
    }
};