class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int l = -1;
        int r = -1;
        int len = 0;
        for(int i = 0; i < n; i++) {
            // odd 
        int d  = 0;
       
        while(i-d >= 0 && i+d < n && s[i-d] == s[i+d]){
            int maxlen = 2* d + 1;
             if(maxlen > len ){
                  len = maxlen ; 
             
                 l = i-d ;
                 r = i+ d;
             
             }
             d++;
    
        }
        
        //even 
        d = 0;
         while(i-d +1 >= 0 && i+d < n && s[i-d + 1] == s[i+d]){
            int maxlen = 2* d;
             if(maxlen > len ){
                  len = maxlen ; 
             
                 l = i-d + 1 ;
                 r = i+ d;
             
             }
             d++;
    
        }
        }
        return s.substr(l, len);
    }
};