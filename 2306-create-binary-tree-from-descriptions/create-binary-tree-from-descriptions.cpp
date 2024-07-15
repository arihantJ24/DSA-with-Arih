class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
         unordered_map<int,TreeNode*>mp;
         unordered_set<int>childVal;
         for(vector<int> & v : descriptions){
            int parent = v[0];
            int child = v[1];
            int isLeft = v[2];

            if(mp.find(parent) == mp.end()){
                mp[parent] = new TreeNode(parent);
            }
            if(mp.find(child) == mp.end()){
                mp[child] = new TreeNode(child);
            }

            if(isLeft == 1){
                mp[parent]-> left = mp[child];
            }
            else{
                mp[parent]->right = mp[child];
            }

            childVal.insert(child);
        }
        
        for(vector<int> & v : descriptions){
            int parent = v[0];
            if(childVal.find(parent) == childVal.end()){
                return mp[parent];
            }
        }
        return NULL;
    }
};