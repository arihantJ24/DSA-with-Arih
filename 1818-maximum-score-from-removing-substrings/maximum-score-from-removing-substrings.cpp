class Solution {
public:
    int remove(string &s , string str, int x){
        int i =0, ans =0;
        for(int j = 0;j<s.size();j++){
            s[i++] = s[j];
            if(i>1 && s[i-2] == str[0] && s[i-1] == str[1] ) i -= 2, ans+=x;
        }
        s.resize(i);
        return ans;
    }
    int maximumGain(string s, int x, int y) {
        string  first = "ab" , second = "ba";
        if(x<y) swap(first, second) , swap(x,y);
        return remove(s,first,x) + remove(s,second, y);
    }
};