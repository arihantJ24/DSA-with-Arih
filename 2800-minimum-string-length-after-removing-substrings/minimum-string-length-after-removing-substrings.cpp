class Solution {
public:
    int minLength(string s) {
        string str;
        for(char c : s){
            if(str.size() && ((str.back() == 'A' && c == 'B') || (str.back() == 'C' && c == 'D') ))
                str.pop_back();
            else
                str.push_back(c);
        }
        return str.size();
    }
};