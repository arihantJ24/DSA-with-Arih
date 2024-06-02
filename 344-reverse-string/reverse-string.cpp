class Solution {
public:
    void reverseString(vector<char>& s) {
        int l  = 0;
        int r = s.size()-1;
        while(l<r){
            char ch1 = s[l];
            char ch2 = s[r];
            s[l] = ch2;
            s[r] = ch1;
            l++, r--;
        }
    }
};