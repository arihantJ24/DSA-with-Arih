class Solution {
public:
    int minSwaps(string s) {
        int len =s.length() ;
        int swaps = 0, balance =0 , j = len -1;
        for(int i =0;i<len;i++){
            if(s[i] == '[') balance++;
            else balance--;

            if(balance < 0){
                while(i<j && s[i] == ']') j--;
                swap(s[i] , s[j]);
                swaps++;
                balance = 1;
            }
        }
        return swaps;
    }
};