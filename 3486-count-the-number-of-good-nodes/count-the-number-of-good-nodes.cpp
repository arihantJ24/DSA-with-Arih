class Solution {
public:
    vector<int>adj[100005];
    int ans = 0 ;
    int dfs(int node , int parent){
        int size = 1;
        unordered_map<int,int> mp;
        for(auto &child : adj[node]){
            if(child != parent){
                int subtree= dfs(child,node);
                size+=subtree;
                mp[subtree]++;
            }
        }
        if(mp.size() <= 1) ans++;
        return size;
    }
    int countGoodNodes(vector<vector<int>>& edges) {
        for (auto& edge : edges) {
            int a = edge[0];
            int b = edge[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(0, -1);
        return ans;
    }
};

