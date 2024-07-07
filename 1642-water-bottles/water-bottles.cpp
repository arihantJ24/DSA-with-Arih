class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int cnt = numBottles;
        int reusable = numBottles/numExchange;
        int rem = numBottles % numExchange;
        while(reusable != 0){
            cnt+= reusable;
            int vacant = reusable+ rem;
            reusable = vacant / numExchange;
            rem = vacant % numExchange;
        }
        return cnt;
    }
};