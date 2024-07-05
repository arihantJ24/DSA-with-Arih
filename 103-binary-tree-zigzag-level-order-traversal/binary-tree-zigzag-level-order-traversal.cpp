class Solution {
public:

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        
        queue<TreeNode*>q;
        q.push(root);
        bool lToR = 1;
        while(!q.empty()){
            int size = q.size();
            vector<int>op(size);
            for(int i = 0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                int index = (lToR)? i : (size-i-1); 
                op[index] = node->val;
                if(node->left) q.push(node->left);
                if(node->right)q.push(node->right);

            }
            lToR = !lToR;
            ans.push_back(op);
        }
        return ans;

    }
};