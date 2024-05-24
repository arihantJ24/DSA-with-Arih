class Solution {
public:
    int n;
    int maxscore;
    void solve(int i ,vector<string>& words, vector<int>& score,int currScore, vector<int>&freq){
         maxscore = max(maxscore,currScore);
        if(i>=n){
            return;
        }
        int tempscore =0;
        vector<int>tempFreq = freq;
        int j = 0;
        // we check word is able to form or not
        while(j<words[i].length()){
            char ch = words[i][j];
            tempFreq[ch-'a']--;
            tempscore += score[ch-'a'];
            if(tempFreq[ch-'a'] < 0)break;

            j++;
        }

        if(j== words[i].length()){ // word successfully create
            solve(i+1,words,score,currScore+tempscore,tempFreq);
        }
        solve(i+1,words,score,currScore,freq);
       

    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        n = words.size();
        vector<int>freq(26,0);
        for(auto & ch : letters){
            freq[ch-'a']++;
        }
        maxscore = INT_MIN;
        solve(0,words,score,0,freq);
        return maxscore;
    }
};