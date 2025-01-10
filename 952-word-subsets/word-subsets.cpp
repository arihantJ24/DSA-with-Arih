class Solution {
    private:
    bool subset(vector<int>temp , vector<int>ch){
        for(int i = 0 ;i< 26;i++){
            if(ch[i]>temp[i])return false;
        }
        return true;
    }
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string>ans;
        vector<int>ch(26);
        for(auto word: words2){
            vector<int>temp(26,0);
            for(int i= 0 ; i<word.length();i++){
                temp[word[i]-'a']++;
            }
            for(int i = 0; i< 26;i++){
                ch[i] = max(ch[i], temp[i]);
            }
        }

        for(auto word: words1){
            vector<int>temp(26,0);
            for(int i= 0 ; i<word.length();i++){
                temp[word[i]-'a']++;
            }
            if(subset(temp,ch))ans.push_back(word);
        }
        return ans;

    }
};

