class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        bool flag = false;
        int cnt = 0;
        for(int i =0;i<arr.size();i++){
            if(arr[i]%2 != 0){
                cnt++;
                if(cnt==3)return 1;
            }
            
            else{
                cnt = 0;
                flag =false;
            }
        }
        return 0;
    }
};