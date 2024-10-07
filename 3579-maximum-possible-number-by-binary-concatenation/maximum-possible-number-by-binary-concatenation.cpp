class Solution {
public:
    string int_to_bit(int n){
        string s = "";
        while(n){
            s = ( n%2 ?  "1" : "0" ) + s;
            n = n/2;
        }
        return s;
    }
    int binary_to_int(string s){
        int ans = 0 , cnt = 0, n =s.size();
        for(int i = n-1;i>=0;i--){
            if(s[i] == '1'){
                ans += pow(2,cnt);
            }
            cnt++;
        }
        return ans;
    }
    int maxGoodNumber(vector<int>& nums) {
        return max({
            binary_to_int(int_to_bit(nums[0]) + int_to_bit(nums[1]) + int_to_bit(nums[2])), 
            binary_to_int(int_to_bit(nums[0]) + int_to_bit(nums[2]) + int_to_bit(nums[1])),
            binary_to_int(int_to_bit(nums[1]) + int_to_bit(nums[0]) + int_to_bit(nums[2])),
            binary_to_int(int_to_bit(nums[1]) + int_to_bit(nums[2]) + int_to_bit(nums[0])),
            binary_to_int(int_to_bit(nums[2]) + int_to_bit(nums[0]) + int_to_bit(nums[1])),
            binary_to_int(int_to_bit(nums[2]) + int_to_bit(nums[1]) + int_to_bit(nums[0]))
        });
    }
};