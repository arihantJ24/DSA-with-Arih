class Solution {
public:
    int minOperations(vector<string>& logs) {
        int cnt =0;
        for(auto & it : logs){

            if(it == "./"){
                if(cnt<0) cnt =0;
                continue;
            }
            else if(it == "../"){
                if(cnt<=0) continue;
                else cnt--;
            }
            else {
cnt++;
            }
            
        }
        return cnt>0 ? cnt : 0;
    }
};