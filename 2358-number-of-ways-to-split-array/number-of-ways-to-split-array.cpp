class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long cnt =0 ;
        long long i =0 ;
        long long n = nums.size();
        long long j = n -1;
        long long sum1 = 0;
        long long sum =0;
        for(auto & it : nums){
          sum += it;
        }

        while(i<j){
            // int sum1 = accumulate(nums.begin(),nums.begin() +i , 0 );
            // int sum2 = accumulate(nums.begin()+i+1 ,nums.begin()+n ,i );
            sum1 += nums[i];
            // int sum2 = 0;
            // for(int k = i+1 ;k<=j;k++){
            //     sum2 += nums[k];
        
            // }
            // cout << sum1 << " " << sum2 <<endl;
            long long sum2 = sum - sum1;
            if(sum1>=sum2) cnt++;

            i = i+1;

        }
        return cnt;
    }
};