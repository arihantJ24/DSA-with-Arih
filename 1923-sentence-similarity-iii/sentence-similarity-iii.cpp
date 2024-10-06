class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        
        if(s1.length() < s2.length()){
            swap(s1,s2);
        } 
        vector<string>v1,v2;
        stringstream ss1(s1);
        string word;
        while(ss1 >> word){
            v1.push_back(word);
        }
        stringstream ss2(s2);
        while(ss2 >> word){
            v2.push_back(word);
        }

        int i = 0 , j = v1.size()-1 , m =0 , n = v2.size() -1;

        while(i<v1.size() && m < v2.size() &&  v1[i] == v2[m]){
            i++, m++;
        }
        while(n>=m &&  v1[j] == v2[n]){
            j--, n--;
        }

        return m>n;
            
        
    }
};