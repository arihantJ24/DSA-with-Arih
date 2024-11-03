class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        int m = goal.size();
         if(n != m) return false ;
        string t = s + s ;
       
      

        for(int i = 0 ;i< t.size() ;i++)
            if( t.substr(i,n)  == goal) return true;

        return false;
    }
};