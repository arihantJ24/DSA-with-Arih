class Solution {
public:

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,int color) {
        if (image[sr][sc] == color) return image;
        int initialColor = image[sr][sc];
        int n = image.size();
        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;
        int drow[4] = {-1, 0, 1, 0};
        int dcol[4] = {0, 1, 0, -1};

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int nrow = row + drow[i];
                    int ncol = col + dcol[i];
                    if (nrow >= 0 && nrow < image.size() && ncol >= 0 &&  ncol < image[0].size() &&
                        image[nrow][ncol] == initialColor) {
                        image[nrow][ncol] = color;
                        q.push({nrow,ncol});
                    }
                }
            }
        }

        return image;
    }
};