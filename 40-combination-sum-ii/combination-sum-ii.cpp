class Solution {   
public:
    void sum2(vector<int>& candidates , int target , int index ,  vector<int>&op ,    vector<vector<int>>&ans ){
        
        if(target == 0){
            ans.push_back(op);
            return ;
        }

        for(int i = index; i< candidates.size() ; i++){
            
            if((i > index) && (candidates[i] == candidates[i-1])) continue;

            if(candidates[i] > target) break;

            op.push_back(candidates[i]);
            sum2(candidates, target - candidates[i], i+1 , op , ans);
            op.pop_back();

        }      
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin() , candidates.end());
        vector<vector<int>>ans;
        vector<int>op;
        sum2(candidates, target , 0 , op , ans);
        return ans;
    }
};