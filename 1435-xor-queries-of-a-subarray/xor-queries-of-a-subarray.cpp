class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        
         int n = arr.size();
        
        vector<int>xorarr(n);
        xorarr[0] = arr[0];
        for(int i =1 ;i< n ;i++){
            xorarr[i] = xorarr[i-1]^ arr[i];
        }
        vector<int>ans;
        // for 2d vector traversal we use
        for(auto &q: queries){
            ans.push_back(xorarr[q[1]] ^ xorarr[q[0]]^  arr[q[0]]);
        }
return ans;
    }
};