class Solution {
    int solve(vector<vector<int>>& books , int shelfWidth ){
        int n = books.size();
        vector<int>minHeight(n+1,INT_MAX);
        minHeight[0] = 0; // base case;
        for(int i = 1;i<=n;i++){
            int currThickness =0 ;
            int currHeight = 0;
            for(int j = i-1 ;j >= 0;j--){
                // same shelf condition
               int currBookThick =books[j][0];
               int currBookHeight = books[j][1];
                if(currThickness + currBookThick > shelfWidth ){
                    break;
                }
                currThickness += currBookThick;
                currHeight = max(currHeight, currBookHeight);

                int possibleHeight = minHeight[j] + currHeight;
                minHeight[i] = min(minHeight[i] ,possibleHeight  );
            }
        }
        return minHeight[n];
    }
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
         return solve(books ,shelfWidth);
    }
};

