class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int mini , maxi ;
        vector <int >v ;
        for (int i = 0 ;i< matrix.size();i++){
            int mini = 999999 ;
            int cnt = 0;
           for (int  j = 0;j<matrix[0].size();j++){
if(mini> matrix[i][j]){
    mini =  matrix[i][j] ;
    cnt =  j ;

}
           }
           maxi = mini ;
             for (int  j = 0;j<matrix.size();j++){
maxi= max(maxi, matrix[j][cnt]);

             }
             if (mini == maxi ){
                 v.push_back(mini);
             }

        }
        return v;
    }
};