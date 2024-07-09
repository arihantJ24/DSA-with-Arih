class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double n = customers.size();
        double waitingTime  = 0 ;
        int currTime =0 ;
        for(auto it :customers ){
            int arrivalTime = it[0];
            int service = it[1];
            if(currTime < arrivalTime){
                currTime = arrivalTime;
            }
            int wait = currTime - arrivalTime + service;
            waitingTime += wait;
            currTime += service;
        }

        return waitingTime/n;
    }
};