class Solution {
public:
    bool judgeSquareSum(int c) {
        int low = 0;
        long long int high = sqrt(c);
        while(low<=high){
            long long int curr = (low*low)+(high*high);
            if(curr < c){
                low++;
            }
            else if (curr > c)high--;
            else return true;
            
        }
        return false;
    }
};