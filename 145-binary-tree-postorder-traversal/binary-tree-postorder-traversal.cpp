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
    vector<int> postorderTraversal(TreeNode* root) {
        // we use two stack first we put node in s1 then pop it from it and push to s2 and traverse the left and right child and push it in s1.. repeat until stack become empty at end in s2 we got the postorder traversla

        vector<int>ans;
        if(!root)return ans;
        stack<TreeNode*>st1;
        stack<TreeNode*>st2;
        
        st1.push(root);
        while(!st1.empty()){
            TreeNode*node = st1.top();
            st1.pop();
            st2.push(node);
            if(node->left) st1.push(node->left);
            if(node->right) st1.push(node->right);
        }

        while(!st2.empty()){
            TreeNode* node = st2.top();
            ans.push_back(node->val);
            st2.pop();
        }
        return ans;
    }
};