//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int mod = (int)1e9+7;
  int f(int i ,vector<int>& arr ,int k ,vector<vector<int>>& dp){
    
      if(i==0){
          if(k==0 && arr[0] ==0)return 2;
          if(k==0 || k == arr[0])return 1;
          return 0;
      }
      if(dp[i][k]!=-1)return dp[i][k];
      
      int notpick =f(i-1,arr,k,dp);
      int pick = 0;
      if(arr[i]<= k){
          pick =f(i-1,arr, k-arr[i],dp);
          
      }
      return  dp[i][k] = (pick + notpick) % mod;
  }
    int countPartitions(int n, int d, vector<int>& arr) {
        int sum = 0;
       
        sum = accumulate(arr.begin(),arr.end(),0);
    
    if(sum-d<0) return 0;
    if((sum-d)%2==1) return 0;
    
        int target = (sum-d)/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return f(n-1,arr,target,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends