class Solution {
public:
    void dfs(int node , vector<int>adjList[] , vector<int>&vis){
        vis[node] = 1;
        for(auto  & it : adjList[node]){
            if(!vis[it]){
                dfs(it , adjList, vis);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        // first make adjacent list
        vector<int>adjList[n];
        for(auto & it :invocations ){
            adjList[it[0]].push_back(it[1]);
        }
        vector<int>vis(n,0);
        dfs(k,adjList,vis);

        bool suspicious = true;
        // check if it's outside are or not

        for(int i = 0;i<n;i++){
            if(!vis[i]){
                for(auto it : adjList[i]){
                    if(vis[it]) suspicious = false;
                }
            }
        }

        vector<int>ans;

        if(suspicious){
            for(int i =0;i<n;i++){
                if(!vis[i]){
                    ans.push_back(i);
                }
            }
        }
        else{
            for(int i =0;i<n;i++){
                ans.push_back(i);
            }
        }
        return ans;
    }
};