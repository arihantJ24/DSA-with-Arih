class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int>freq(26,0);
        vector<int>visited(26,0);

        for(int i=0;i<s.length();i++){
            freq[s[i] - 'a']++;
        }

        string ans = "";
        for(int i =0 ; i<s.length();i++){
            freq[s[i]-'a']--;
            if(!visited[s[i]-'a']){
                while(ans.length()>0 && ans.back() > s[i] && freq[ans.back()-'a'] > 0){
                    visited[ans.back()-'a'] = 0;
                    ans.pop_back();
                }
                ans += s[i];
                visited[s[i]-'a'] = 1;
            } 
        }
      return ans;
    }
};