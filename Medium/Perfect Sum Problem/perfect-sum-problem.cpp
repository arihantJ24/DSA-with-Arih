//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int MOD = 1e9+7;
	int f(int arr[], int i ,int k, 	vector<vector<long long >>&dp){
	    if(i == 0){
	        if(k==0 && arr[0] == 0)return 2;
	        if(k == 0 || k== arr[0]) return 1;
	        return 0;
	    }
	    if(dp[i][k]!=-1)return dp[i][k];
	    int notpick = f(arr,i-1,k,dp);
	    int pick =0;
    	if(arr[i]<= k)pick =  f(arr,i-1,k-arr[i],dp);
    
    	return 	dp[i][k] = (pick+notpick)%MOD;
	    
	}
	int perfectSum(int arr[], int n, int k)
	{
    	vector<vector<long long >>dp(n,vector<long long >(k+1,-1));
        return f(arr,n-1,k,dp);
    	
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends