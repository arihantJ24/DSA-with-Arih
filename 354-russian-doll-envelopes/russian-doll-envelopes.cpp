class Solution {
public:
    static bool cmp(vector<int>&a, vector<int>&b ){
        return a[0] == b[0] ? a[1]>b[1] : a[0]<b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end() , cmp);
        vector<int>temp;
        int len = 1;
        vector<int>val;
        for(auto & it : envelopes){
            val.push_back(it[1]);
        }
        // for(int i =0;i< val.size();i++) cout << val[i] << " "<<endl;
        temp.push_back(val[0]);
        for(int i = 1;i<val.size();i++){
            if(val[i] > temp.back()){
                temp.push_back(val[i]);
                len++;
            }
            else{
                int ind = lower_bound(temp.begin(),temp.end(),val[i]) - temp.begin();
                temp[ind] = val[i];
            }
        }
        return len;
    }
};