class Solution {
public:
    int maxDepth(string s) {
        int curr = 0, ans = 0;
        for(int i =0 ; i<s.length() ; i++){
            if(s[i] == '(')curr++;
            else if(s[i] == ')')curr --;
            ans = max(curr, ans);
        }
        return ans;
    }
};