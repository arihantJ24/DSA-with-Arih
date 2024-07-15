/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int i =0;
    void inorder(TreeNode*root ,vector<int> & ans){
        if(root == NULL) return ;
        
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    void checkBst(vector<int>&ans, TreeNode*root){
        if(root == NULL) return ;
       
        checkBst(ans, root->left);
        if(ans[i] != root->val ) swap(ans[i] , root->val);
        i++;
        checkBst(ans, root->right);
    }
    void recoverTree(TreeNode* root) {
        vector<int>ans;
        inorder(root, ans);
        sort(ans.begin(),ans.end());
        checkBst(ans,root);
    }
};