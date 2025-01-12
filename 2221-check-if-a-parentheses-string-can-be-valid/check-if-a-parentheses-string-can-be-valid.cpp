class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();
        if(s.length() % 2 != 0) return 0;
        int openCnt = 0 , closeCnt =0;

        for(int i = 0 ; i < n ;i++){
            if(s[i] == '(' || locked[i] == '0') openCnt++;
            else openCnt --;

            if(openCnt <0) return false;
            
        }
        openCnt = 0;
        for(int i = n-1 ; i >= 0 ;i--){
            if(s[i] == ')' || locked[i] == '0') closeCnt++;
            else closeCnt --;
            if(closeCnt <0) return false;
           
        }

        return true;
    }
};