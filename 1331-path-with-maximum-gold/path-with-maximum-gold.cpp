class Solution {
public:
    int maxi, n ,m;
    int getMaximumGold(vector<vector<int>>& grid) {
        n = grid.size();
        m =grid[0].size();
        for(int i = 0 ; i< n ;i++){
            for(int j = 0 ;j<m ; j++){
                if(grid[i][j]!= 0){
                    solve(grid, i , j ,0);
                }
            }
        }
        return maxi;
    }
    void solve(vector<vector<int>>& grid , int row ,int col , int curr){
        if(row<0 || row>=n || col<0 || col>=m || grid[row][col] == 0){
            maxi = max(maxi,curr);
            return; 
        }
        int val = grid[row][col];
        grid[row][col] =0;
        solve(grid, row+1 , col , curr+val);
        solve(grid, row-1 , col , curr+val);
        solve(grid, row , col+1 , curr+val);
        solve(grid, row , col -1 , curr+val);
        grid[row][col] =val;
    }
};