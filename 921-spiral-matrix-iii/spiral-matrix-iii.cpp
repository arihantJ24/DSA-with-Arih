class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int r, int c) {
        vector<vector<int>> ans = {{r,c}};
        int dx = 0, dy =1;
        for(int n = 0 ;ans.size()<rows*cols ; n++){
            for(int i = 0 ; i< n/2+1; i++){
                r+=dx , c+=dy;
                if(0<=r && r<rows && 0<=c && c<cols)
                ans.push_back({r,c});
            }
            int temp = dx;
            dx = dy;
            dy = -temp;
        }
        return ans;
    }
};