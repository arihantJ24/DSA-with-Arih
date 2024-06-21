class Solution {
public:
    void bfs(int row, int col , vector<vector<int>>& board ,vector<vector<int>> &vis){
        int n = board.size();
        int m = board[0].size();
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        queue<pair<int,int>>q;
        q.push({row,col});
        while(!q.empty()){
            int row = q.front().first;
            int col =q.front().second;
            q.pop();
            vis[row][col] = 1;
            for(int i = 0;i<4;i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(nrow>=0 && nrow < n &&  ncol >= 0 && ncol< m && vis[nrow][ncol] == 0 && board[nrow][ncol] == 1){      
                    vis[nrow][ncol] =1;
                    q.push({nrow,ncol});
                } 
        }
    }
}
    int numEnclaves(vector<vector<int>>& board) {
        int cnt = 0;
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int j = 0;j<m;j++){
            if(vis[0][j] == 0 &&  board[0][j] == 1){
                // dfs(0,j,board,vis);
                bfs(0,j,board,vis);

            }

            if(vis[n-1][j] == 0 &&  board[n-1][j] == 1){
                // dfs(n-1,j,board,vis);
                bfs(n-1,j,board,vis);

            }
        }
        for(int i = 0;i<n;i++){
            if(vis[i][0] == 0 &&  board[i][0] == 1){
                // dfs(i,0,board,vis);
                bfs(i,0,board,vis);

            }
            if(vis[i][m-1] == 0 &&  board[i][m-1] == 1){
                // dfs(i,m-1,board,vis);
                bfs(i,m-1,board,vis);

            }
        }

        for(int i = 0;i<n;i++){
            for(int j = 0 ;j<m ;j++ ){
                if(vis[i][j] != board[i][j]) cnt++;
            }      
            
        }
        
        return cnt;
    }
};