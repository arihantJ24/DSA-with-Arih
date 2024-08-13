class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        int cnt =0;
        vector<vector<int>>v(10,vector<int>(11,0));
        for(int i =0;i<pick.size();i++){
           v[pick[i][0]][pick[i][1]]++;
        }
        for(int i =0;i<n;i++){
            for(int j = 0;j<11;j++){
                if(v[i][j] >= i+1){
                    cnt++;
                    break;
                }
            }
        }

        return cnt;
        
    }
};