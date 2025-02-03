class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        vector<int> inc(n, 1);
        vector<int> dec(n, 1);

        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i-1]) {
                inc[i] = inc[i-1] + 1;
            }
            if (nums[i] < nums[i-1]) {
                dec[i] = dec[i-1] + 1;
            }
        }

        int maxi = 1;
        for (int i = 0; i < n; ++i) {
            maxi = max(maxi, max(inc[i], dec[i]));
        }

        return maxi;
    }
};