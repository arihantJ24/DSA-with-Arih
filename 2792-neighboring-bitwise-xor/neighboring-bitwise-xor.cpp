class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        // int n = derived.size();
        // vector<int>original1(n);
        // vector<int>original2(n);
        // original1[0] = 0;
        // original2[0] = 1;
        // for(int i =0;i< n-1 ;i++){
        //     original1[i+1] = original1[i] ^ derived[i];
        //     original2[i+1] = original2[i] ^ derived[i];
        // }
        // if( ((original1[0] ^ original1[n-1]) == derived[n-1] ) || ((original2[0] ^ original2[n-1]) == derived[n-1] )){
        //     return true;
        // }
        // else return false;
        int Txor = 0 ;
        for(auto it: derived){
            Txor ^= it;
        }

        return Txor == 0 ? true : false;

    }
};