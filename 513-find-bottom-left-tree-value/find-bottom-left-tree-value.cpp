class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {

        queue<TreeNode*>q;
        q.push(root);
        //this is to break the level
        q.push(NULL);
        int flag = 1;
        int leftNode = q.front()->val;

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node== NULL){
                // check for new level
                if(!q.empty()){
                    q.push(NULL);
                }
                flag = 1;
            }
            else{
                if(flag){
                leftNode = node->val;
                }
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
                flag = 0;
            }
            
        }
        return leftNode;
    }
};