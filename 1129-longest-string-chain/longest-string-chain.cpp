class Solution {
    
public: 
    // s is greater than t
    bool compare(string &s ,string &t){
        int n = s.length() , m = t.length();
        if(n != m+1)return false;
        int i = 0 ,j =0;
        while(i<n ){
            if(j<m && s[i]== t[j]) i++, j++;
            else i++;
        }
        if(i==n && j== m)return true;
        else return false;
    }
    bool static comp(string &s1 , string &s2){
        return s1.size() < s2.size();
    }
    int longestStrChain(vector<string>& words) {
        int n= words.size();
        sort(words.begin(),words.end(),comp);
        vector<int>dp(n+1,1);    
        for(int i =0;i<n;i++){
            for(int prevIdx = 0;prevIdx < i;prevIdx++){
                if(compare(words[i],words[prevIdx]) &&  1+dp[prevIdx] >dp[i] ){
                    dp[i] = 1+dp[prevIdx];
                }
            }         
        }
        return *max_element(dp.begin(),dp.end());
    }
};