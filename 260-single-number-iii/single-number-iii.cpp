class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xor1 = 0;
        for(auto  & it : nums) xor1 ^= it;
        int idx = 0;
        for(int i = 0 ;  i<32 ; i++){
            // To find set bit
            if(xor1 &(1<<i)){
                idx = i;
                break;
            }
        }
        int firstbitxor = 0;
        for(auto & ele : nums){
            if(ele &(1<<idx)) firstbitxor ^= ele;
        }
        return {firstbitxor, xor1^firstbitxor};
    }
};