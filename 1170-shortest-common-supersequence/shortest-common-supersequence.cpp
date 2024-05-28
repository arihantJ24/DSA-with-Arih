class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        /* find the lcs that is the longest common part between two string
        so if we want to makema shortest common supersequence in which both str1 and str2 will there 
        we can combine the str1 and str2 and subtract that longest common subsequence from total string and we get the
        shortestCommonSupersequence as we subtracting the LCS we get by default the shortest one... */ 
        int n= str1.length();
        int m = str2.length();

        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                if(str1[i-1] == str2[j-1]) dp[i][j] = 1+ dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        // so as we know dp[n][m] store the length of longest common subsequence now we find the string

        int length = dp[n][m];
        int i = n , j = m;
        string ans = "";
        while(i>0 && j>0){
            if(str1[i-1] == str2[j-1]){
                ans += str1[i-1];
                i--; j--; 
            }
            else{
                if(dp[i-1][j]> dp[i][j-1]){
                    ans += str1[i-1];
                    i--;
                }
                else {
                    ans+= str2[j-1];
                    j--;
                }
            }
        }

        while(i>0)ans+= str1[i-1], i--;
        while(j>0)ans+= str2[j-1], j--;

        reverse(ans.begin(),ans.end());

        return ans;

        
        
    }
};