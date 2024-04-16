class Solution {
public:
    TreeNode* addval(TreeNode* root, int val, int depth , int curr){
        if(!root)
        return NULL;
        if(curr == depth-1){
            TreeNode * leftTemp = root->left;
            TreeNode* rightTemp = root->right;

            root->left = new TreeNode(val);
            root->right = new TreeNode(val);

            root->left->left = leftTemp;
            root->right->right = rightTemp;

            return root;
        }

        root->left = addval(root->left, val , depth ,curr+1);
        root->right = addval(root->right, val , depth ,curr+1);

        return root;


    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode*newnode = new TreeNode(val);
            newnode->left = root;
            return newnode;
        }
        int curr = 1;
        return addval(root, val , depth , curr);
    }
};