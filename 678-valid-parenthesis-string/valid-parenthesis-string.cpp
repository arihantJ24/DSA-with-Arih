class Solution {
public:
    bool checkValidString(string s) {
        int c1= 0 , c2 = 0;
        for(int i =0 ; i< s.length();i++){
            if(s[i] == '(')c1++;
            else c1--;
            if(s[i] != ')') c2++;
            else c2--;
            if(c2<0)return false;
            c1 = max(0,c1);
        }
        return c1 == 0;
    }
};