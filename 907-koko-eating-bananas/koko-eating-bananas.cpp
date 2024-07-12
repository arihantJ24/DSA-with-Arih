class Solution {
public:
    bool  helper(int mid, vector<int>& piles, int h){
        int cnt = 0;
        for(int i = 0;i<piles.size();i++){
            if(piles[i]% mid != 0){
                cnt += 1+ piles[i] / mid;
            }
            else{
                cnt += piles[i] / mid;
            }
        }
        if(cnt<=h) return true;
        else return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int n = piles.size();
        int s = 1;
        int e = piles[n-1];
        while(s<e){
            int mid = s+(e-s)/2;
            if(helper(mid,piles,h)){
                e = mid;
            }
            else{
                s = mid+1;
            }
        }
        return e;
    }
};