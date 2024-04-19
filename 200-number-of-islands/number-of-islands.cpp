class Solution {
private:
void dfs(int row , int col  ,vector<vector<char>>& grid ){
    int n = grid.size();
    int m = grid[0].size();

    if(row<0 || col<0 || row >= n || col>= m || grid[row][col] == '0') return ;

    grid[row][col] = '0';

    dfs(row+1 ,col ,grid);
    dfs(row-1 ,col ,grid);
    dfs(row ,col+1,grid);
    dfs(row ,col -1 ,grid);

}
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
         
        int cnt =0 ;
        for(int row = 0 ; row < n ;row++){
            for(int col = 0 ; col < m ; col++){
                if(grid[row][col] == '1'){  
                    cnt++;               
                    dfs(row ,col , grid);
                    
                }
            }
        }
        return cnt ;
    }
};