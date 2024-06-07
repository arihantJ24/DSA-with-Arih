class Solution {
public:
    int f(int i , int j, vector<int>& cuts,vector<vector<int>>&dp ){
        if(i>j) return 0;
        int mini = 1e9;
        if(dp[i][j]!= -1)return dp[i][j];
        for(int idx = i; idx <= j ; idx++){
            int steps=cuts[j+1] - cuts[i-1]+f(i,idx-1,cuts,dp) + f(idx+1,j,cuts,dp);
            mini = min(steps,mini);
        }
        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        int cutArrSize = cuts.size();
        cuts.push_back(n); // this push length in back
        cuts.push_back(0);
        sort(cuts.begin(),cuts.end());

        vector<vector<int>>dp(cutArrSize+1,vector<int>(cutArrSize+1,-1));
        return f(1,cutArrSize,cuts ,dp);
    }
};