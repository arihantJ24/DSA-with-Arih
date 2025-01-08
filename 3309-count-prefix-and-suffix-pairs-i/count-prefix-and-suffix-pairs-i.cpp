class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int cnt = 0;
        int n =words.size();
        for(int i = 0;i<n;i++){
            string str1 = words[i];
            for(int j = i+1; j< n; j++){
                string str2 = words[j];
                if(str2.length() < str1.length()) continue;
                string pre = str2.substr(0,str1.length());
                string suf = str2.substr(str2.length() - str1.length());
                if(pre == str1 && suf == str1) cnt++;

            }
        }
        return cnt;
    }
};