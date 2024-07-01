class Solution {
public:
    static bool cmp(vector<int>&a, vector<int>&b){
        return a[0] == b[0] ? a[1] > b[1]  : a[0] < b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end() , cmp);

        int cnt = 0;
        // [1 5] [4 3] [10 4]
        int mini = INT_MIN;
        for(int i = arr.size()-1;i>=0;i--){
             if(arr[i][1] < mini){
                cnt++;
             }
             mini = max(mini, arr[i][1]);
        }

        return cnt;
    }
};