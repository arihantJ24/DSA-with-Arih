class Solution {
    private:
    bool static cmp(pair<int,int>a, pair<int,int>b){
        if(a.second == b.second){
            return a.first>b.first;
        }
        return a.second<b.second;
    }
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int>ans;
        map<int,int>mp;
        for(int i =0;i<nums.size();i++){
            mp[nums[i]]++;        
        }
        vector<pair<int,int> >v;
        for(auto  & it : mp ) v.push_back({it.first,it.second});
        sort(v.begin(),v.end(),cmp);
        for(auto & it : v){
            int value = it.first;
            int freq = it.second;
            while(freq--){
                ans.push_back(value);
            }
        }
        return ans;
    }
};