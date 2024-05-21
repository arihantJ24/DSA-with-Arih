class Solution {
public:
    int solve(int index , int jump, bool canJumpAgain,int k,unordered_map<string,int>&mp){
        // base case 
        // if she jump nd i > K+1 so she can reach to k because she cannot downstair continuously
        if(index>k+1) return 0;
        int totalWays =0;

        // For memoization we store it in key value pair
        string key = to_string(index) +'_' + to_string(jump) + '_' + to_string(canJumpAgain);

        if(mp.find(key)!= mp.end())return mp[key];

        if(index == k) totalWays+=1;
        // we have two operation 1. going down(i-1){ consecutive not allow} 2. jumping (i+ 2^jump) {jump increment to jump++}
        // but case 1. tbhi possible hai jab canJumpAgain true ho
        if(canJumpAgain == true){
            totalWays += solve(index-1,jump,false, k, mp);
        }
        // case 2. jump = jump+1
        totalWays += solve(index + pow(2,jump), jump+1 ,true, k, mp);
        return mp[key] = totalWays;
    }
    int waysToReachStair(int k) {
        
        // given that she starting from index 1, starting jump = 0 ,nd initially she 
        //can go to down stair so ek flag rakh lenge nd usko true mark kr lenge
        // To store this we use memoization 
        unordered_map<string,int>mp;
        return solve(1,0,true,k , mp);
    }
};