class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<long long, vector<long long> ,greater<long long>>pq;
        pq.push(1);
        int cnt= 0;
        long long ans = 0;
        while(!pq.empty() && cnt != n ){
            long long number = pq.top();
            ans = number;
            for(auto & p : primes)pq.push(p*number);
            while(pq.top()== number && !pq.empty()) pq.pop();
            cnt++;
        }
        return ans;
    }
};