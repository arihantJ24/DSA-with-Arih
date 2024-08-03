class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
       
        unordered_map<int,int>mp1;
        unordered_map<int,int>mp2;
        for(auto it : target){
            mp1[it]++;
        }
        for(auto it : arr){
            mp2[it]++;
        }

        if(mp1!= mp2)return false;
        else return true;
    }
};