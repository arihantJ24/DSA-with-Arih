class Solution {
private:
TreeNode*deleteNode(TreeNode* root,unordered_set<int>&st,vector<TreeNode*>& forest){
        if(!root)return NULL;

        root->left = deleteNode(root->left, st,forest);
        root->right = deleteNode(root->right, st,forest);
        if(st.find(root->val)!= st.end()){
            if(root->left) forest.push_back(root->left);
            if(root->right)  forest.push_back(root->right);
            return NULL;
        }
        return root;    
    }
    public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*>forest;
        unordered_set<int>st(to_delete.begin(), to_delete.end());
        deleteNode(root, st,forest);
        if(root && st.find(root->val) == st.end()) {
            forest.push_back(root);
        }
        return forest;
    }
};