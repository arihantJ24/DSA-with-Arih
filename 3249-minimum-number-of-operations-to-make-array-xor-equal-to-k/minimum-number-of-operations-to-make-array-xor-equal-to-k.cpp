class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
    int xor1 = 0;
    for (int a : nums) {
        xor1 ^= a;
    }

    int xor2 = xor1 ^ k;
    int cnt = 0;

    while (xor2 != 0) {
        cnt += xor2 & 1;
        xor2 >>= 1;
    }

    return cnt;
    }
};