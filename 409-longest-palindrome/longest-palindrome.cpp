class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.length();
        int odd = 0;
        map<char,int>mp;
        for(char ch : s){
            mp[ch]++;
            if(mp[ch] % 2 == 1){
                odd++;
            }
            else odd--;
        }
        if(odd>1)return n- odd +1;
        else return n;
    }
};