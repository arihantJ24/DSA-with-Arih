class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        /* first we take a map in which initially we mark every 
        character to some highest frequency value, we have only 26 characters*/
        unordered_map<char,int> minFreq;

        for(char ch = 'a'; ch<='z'; ch++){
            minFreq[ch] = 1000;
        }
        /* now let's calculate the freq of each word and update each word's character
        frequecy with minFreq character's value*/
        for(auto word : words){
            // iterate over each character of each word and store it frequency in mp
            unordered_map<char,int>mp1;
            for(auto it: word){
                mp1[it]++;
            }
            // now update character freq in minimum frequency map
            for(auto ch = 'a' ;ch<= 'z' ;ch++){
                minFreq[ch] = min(minFreq[ch],mp1[ch]);
            }
        }

        /* at end we update the minimum frequency map.. in this way our map store 
        only those character who are common in all and rest are 0 
        so just simple traverse over map and print it in form of vector string*/
        vector<string>ans;
        for(auto ch = 'a'; ch<='z'; ch++){
            while(minFreq[ch]>0){
                string temp;
                temp.push_back(ch);
                ans.push_back(temp);
                minFreq[ch]--;
            }
        }
        return ans;
    }
};