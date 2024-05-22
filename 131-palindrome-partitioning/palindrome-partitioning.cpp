class Solution {
public:
    bool isPalindrome(string& s, int i ,int j){
        while(i<j){
            if(s[i]!=s[j])return false;
            i++,j--;
        }
        return true;
        
    }
    void solve (string & s, int idx,vector<vector<string>>&ans, vector<string>&temp){
        //base case
        int n = s.length();
        if(idx == n){
            ans.push_back(temp);
            return;
        }
        for(int i = idx;i<n;i++){
            if(isPalindrome(s,idx,i)){
                temp.push_back(s.substr(idx,i-idx+1));
                solve(s,i+1,ans,temp);
                temp.pop_back(); // backtracking
            }
        }

    }
    vector<vector<string>> partition(string s) {
        vector<string>temp;
        vector<vector<string>> ans;
        solve(s,0,ans,temp); // 0 -> is representing the index
        return ans;
    }
};