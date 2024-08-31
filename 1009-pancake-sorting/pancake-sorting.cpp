class Solution {
public:
    void flip(vector<int>&arr, int k){
        int s = 0;
        while(s<=k){
            swap(arr[s++], arr[k--]);
        }
    }
    int max_val(vector<int>&arr, int k){
        int val = INT_MIN;
        int idx;
        for(int i =0;i<=k;i++){
            if(val<arr[i]){
                val = arr[i];
                idx = i;
            }
        }
        return idx;
    }
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int>ans;
        int k = arr.size()-1;
        while(k>=0){
            int idx = max_val(arr,k);
            flip(arr,idx);
            ans.push_back(idx+1);
            flip(arr,k);
            ans.push_back(k+1);
            k--;
        }
        return ans;
    }
};