//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#include <bits/stdc++.h>
class Solution
{
    public:
    
    int f(int idx, int prev_idx ,int n, int nums[],vector<vector<int>>&dp){
        if(idx == n)return 0;
        if(dp[idx][prev_idx+1] !=-1) return dp[idx][prev_idx+1];

        //notpick
        int notpick = 0+f(idx+1,prev_idx,n,nums,dp);
        int pick = -1e9;
        if(prev_idx== -1 || nums[idx]>nums[prev_idx]){
            pick = 1+f(idx+1,idx,n,nums,dp);
        }
        return dp[idx][prev_idx+1] = max(pick,notpick); 
    }
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int nums[])
    {

        // vector<vector<int>>dp(n,vector<int>(n+1,-1));
        // return f(0,-1,n,a,dp);
        // vector<int>dp(n,1);
        // for(int i = 0;i<n;i++){
        //     for(int prevIdx = 0; prevIdx< i; prevIdx++){
        //         if(nums[prevIdx]<nums[i]){
        //             dp[i] = max(dp[i], 1+dp[prevIdx]);
        //         }
        //     }
        // }
        // return *max_element(dp.begin(),dp.end());
        
        vector<int>temp;
        temp.push_back(nums[0]);
        int len = 1;
        for(int i = 1;i<n;i++){
            if(nums[i]>temp.back()){
                temp.push_back(nums[i]);
                len++;
            }
            else{
                int ind = lower_bound(temp.begin(),temp.end(), nums[i])-temp.begin();
                temp[ind] =nums[i];
            }
        }
        return len;
       
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends