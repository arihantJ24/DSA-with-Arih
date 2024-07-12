class Solution {
public:
    bool possible(long long mid,vector<int>& candies, long long k ){
        long long cnt = 0;
        for(int i =0;i<candies.size();i++){
            cnt += (candies[i]/mid);
            if(cnt>=k)return true;
        }
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int maxi = 0;
        for(int i =0;i<candies.size();i++){
            maxi = max(maxi,candies[i]);
        }
        long long s = 1;
        long long e = maxi;
        long long ans= 0;
        while(s<=e){
            long long mid = s+(e-s)/2;
            if(possible(mid, candies,k)){
                ans = mid;
                s = mid+1;
            }
            else{
                e =mid-1;
            }
        }

        return ans ;
    }
};