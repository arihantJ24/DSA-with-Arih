class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        sort(costs.begin(),costs.end());
        int cnt = 0;
        for(int i =0 ; i<n ; i++){
            coins = coins - costs[i]; // -5
            
            if(coins<0) break;
            cnt++;
     
        }
        return cnt;
    }
};