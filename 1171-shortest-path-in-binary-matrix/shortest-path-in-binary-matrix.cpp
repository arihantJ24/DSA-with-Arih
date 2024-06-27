class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int lvl = 0;
        queue<pair<int,int>>q;
        
        q.push({0,0});
        if(grid[0][0] == 1)return -1;
        int dx[]={0,0,1,1,1,-1,-1,-1};
        int dy[]={1,-1,0,1,-1,0,1,-1};
    
        while(!q.empty()){
            int size = q.size();
            lvl++;
            while(size--){
                auto it = q.front();
                q.pop();
                int row = it.first;
                int col = it.second;
                if(row == n-1 && col == n-1) return lvl;

                for(int i = 0;i<8;i++){

                        int nrow = row+dx[i];
                        int ncol = col + dy[i];
                        if(nrow>= 0 && ncol>= 0 && nrow < n && ncol < n && grid[nrow][ncol]  == 0 ){
                            grid[nrow][ncol] = 1;
                            q.push({nrow,ncol});
                        }
                    
                }
            
            }
        }


        return -1;
    }
};