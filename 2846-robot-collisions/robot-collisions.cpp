class Solution {
public:
bool cmp(int i, int j, const vector<int>& positions) {
    return (positions[i] < positions[j]) ;
}
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n =positions.size();
        vector<int>orignalIdx(n);
        for(int i = 0;i<n;i++){
            orignalIdx[i] = i;
        }
        sort(orignalIdx.begin() , orignalIdx.end() , [&](int i , int j){return cmp(i, j, positions); });
        stack<int>st;
        for(int idx: orignalIdx ){
            if(directions[idx] == 'R'){
                st.push(idx);
            }
            else{
                while(!st.empty() && healths[idx]>0){
                    int val = st.top();
                    st.pop();
                    if(healths[val] > healths[idx]){
                        healths[val] -= 1;
                        healths[idx] = 0;
                        st.push(val);
                    }
                    else if(healths[val]<healths[idx]){
                        healths[idx] -= 1;
                        healths[val] =0;
                    }
                    else{
                        healths[idx] = 0;
                        healths[val] =0;
                    }
                }
            }
        }
        vector<int> ans;
       
        for(int i =0 ;i<n;i++){
            if(healths[i]>0){
                ans.push_back(healths[i]);
            }
        }
        return ans;
    }
};