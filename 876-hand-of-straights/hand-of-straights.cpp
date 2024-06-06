class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        int n = hand.size();
        if(n % groupSize != 0)return false;
        map<int,int>mp;
        for(auto &num : hand){
            mp[num]++;
        }

        int totalGroup = n / groupSize;

        for(int i = 1 ;i<= totalGroup ;i++){
            auto it = mp.begin(); // first pair of map
            int temp = it->first; // here we store the first element
            for(int j = temp ;j< temp + groupSize ;j++){
                if(mp.find(j) == mp.end()) return false;
                mp[j]-- ; //decrement the frequency
                if(mp[j] == 0){
                    mp.erase(j); // if mp[j] == 0 we remove that pair
                }
            }
        }
        return true;     
    }
};