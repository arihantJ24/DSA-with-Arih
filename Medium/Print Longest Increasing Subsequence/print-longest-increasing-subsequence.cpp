//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        // Code here
        vector<int>dp(n+1,1);
        vector<int>hash(n,1);
        for(int i = 0;i<n;i++){
            hash[i] =i; 
            for(int prevIdx = 0 ;prevIdx <= i-1 ;prevIdx++){
                if(arr[prevIdx] < arr[i] && 1 + dp[prevIdx] > dp[i] ){
                    dp[i] = 1+dp[prevIdx];
                    hash[i] = prevIdx;
                }
            }
        }
        int ans =-1;
        int lastIndex= -1;
        
        for(int i = 0;i<n;i++){
            if(dp[i]>ans){
                ans = dp[i];
                lastIndex = i;
            }
        }
        vector<int>temp;
        temp.push_back(arr[lastIndex]);
        while(hash[lastIndex] != lastIndex){
            lastIndex = hash[lastIndex];
            temp.push_back(arr[lastIndex]);
        }
        reverse(temp.begin(),temp.end());
        return temp;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends