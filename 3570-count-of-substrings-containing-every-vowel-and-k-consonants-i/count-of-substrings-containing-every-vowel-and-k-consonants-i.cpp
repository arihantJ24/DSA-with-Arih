class Solution {
public:
    int countOfSubstrings(string word, int k) {
        int substring = 0;
        unordered_set<char>vowel = { 'a' , 'e' , 'i' , 'o' ,'u'};
        for(int i =0;i<word.size();i++){
            unordered_set<char>st;
            int cnt = 0;
            for(int j = i; j<word.size();j++){
                if(vowel.find(word[j]) != vowel.end()){
                    st.insert(word[j]);
                }
                else{
                    cnt++;
                }

                if(st.size() == 5 && cnt == k){
                    substring++;
                }
            }
        }
        return substring;
        
    }
};