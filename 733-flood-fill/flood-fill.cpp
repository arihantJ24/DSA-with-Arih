class Solution {
public:
void dfs(int row ,int col , int initialColor , int color,vector<vector<int>>& image ,vector<vector<int>>& newMat ){
    newMat[row][col] = color;
    int drow[4] = {-1,0,1,0};
    int dcol[4] = {0,1,0,-1};

    for(int i = 0 ;i<4;i++){
        int nrow = row + drow[i];
        int ncol = col + dcol[i];

        if(nrow >= 0 && nrow < image.size() && ncol >= 0 && ncol < image[0].size() &&
        image[nrow][ncol] == initialColor && newMat [nrow][ncol] != color ){
            dfs(nrow, ncol , initialColor , color ,image, newMat);
        }
    }
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> newMat = image;
        int n = image.size();
        int initialColor = image[sr][sc];
        dfs(sr,sc,initialColor,color,image,newMat);
        return newMat;
    }
};