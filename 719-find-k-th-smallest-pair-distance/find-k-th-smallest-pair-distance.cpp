class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int l =0 , r = nums[n-1]-nums[0];
        while(l<r){
            int mid = (l+r)/2;
            int cnt = 0;
            int i = 0, j = 1;
            while(i<n){
                while(j<n && nums[j] - nums[i] <= mid){
                    j++;
                }
                cnt += j-i-1;
                i++;
            }

            if(cnt>=k) r = mid;
            else l = mid+1;
        }
        return l;
        
    }
};