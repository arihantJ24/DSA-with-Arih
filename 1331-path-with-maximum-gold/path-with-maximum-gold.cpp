class Solution {
public:
    vector<vector<int>> direction {{-1,0}, {0,1} , {0,-1} , {1,0}};
    int dfs(vector<vector<int>>& grid, int row , int col , int m ,int n){
        if(row >=m || row<0 || col >=n || col<0 || grid[row][col] == 0){
            return 0;
        }
        int originalvalue = grid[row][col];
        grid[row][col] = 0;
        int maxgold = 0;
        // direction

        for(vector<int>&dir : direction){
            int new_i = row + dir[0];
            int new_j = col+ dir[1];

            maxgold = max(maxgold , dfs(grid, new_i , new_j , m ,n));
        }
        
        grid[row][col] = originalvalue ;
        return maxgold + originalvalue ;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxGold = 0;
        for(int i =0 ;i< m ;i++){
            for(int j =0;j<n;j++){
                if(grid[i][j]!=0){
                    maxGold = max(maxGold, dfs(grid,i,j,m,n));
                }
            }
        }
        return maxGold;
    }
};