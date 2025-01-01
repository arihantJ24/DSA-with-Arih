class Solution {
public:
    int maxScore(string s) {
        
        int zeroes = 0;
        int ones= count(s.begin(), s.end(), '1');
        int ans =0;
        for(int i = 0;i<s.length()-1;i++){
            zeroes += (s[i] == '0'); 
            ones -= (s[i] == '1');
            ans = max(ans, zeroes+ones) ;
        }
        return ans;
    }
};