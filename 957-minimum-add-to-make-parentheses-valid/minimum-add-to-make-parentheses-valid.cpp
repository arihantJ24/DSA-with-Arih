class Solution {
public:
    int minAddToMakeValid(string s) {
        vector<char>v;
        int cnt = 0;
        for(auto & it : s){
            if(it == '(')v.push_back(it);
            else{
                if(v.empty())cnt++;
                else v.pop_back();
            }
        }
        return cnt+v.size();
    }
};