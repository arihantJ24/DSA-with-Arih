class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans =0;
        for(string & st : details ){
            ans += (st[11] > '6' || st[11] == '6' && st[12] > '0');
            
            }
            return ans;
        
    }
};