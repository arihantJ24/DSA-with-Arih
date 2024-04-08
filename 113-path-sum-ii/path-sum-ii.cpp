class Solution {
public:
    vector<vector<int>> ans;
    void traverse(TreeNode* root,int sum , vector<int>temp,int &targetSum){
        if(!root)return;
        sum+= root->val;
        temp.push_back(root->val);
        if(root->left == NULL && root->right == NULL )
        {
            if(sum == targetSum){
                ans.push_back(temp);
            }
            return ;
        }
        traverse(root->left, sum , temp , targetSum);
        traverse(root->right, sum , temp , targetSum);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>temp;
        int sum = 0 ;
        traverse(root, sum , temp , targetSum);
        return ans;
    }
};