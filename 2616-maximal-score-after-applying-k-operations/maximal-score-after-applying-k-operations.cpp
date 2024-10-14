class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int>pq;
        for(auto it : nums){
            pq.push(it);
        }

        long long score = 0;
        while(k--){
            int top = pq.top();
            pq.pop();
            score+= top;
            int newtop = ceil(top/3.0);
            pq.push(newtop);
        } 
        return score;
    }
};