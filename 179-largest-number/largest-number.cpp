class Solution {
public:
    static bool cmp(string & a , string & b){
        string ab = a+b ;
        string ba = b+a;
        return ab>ba;
    }
    string largestNumber(vector<int>& nums) {
        vector<string>str;
        for(int num : nums){
            str.push_back(to_string(num));
        }
        sort(str.begin(),str.end(),cmp);
        string largest = "";
        for(auto & s : str){
            largest += s;
        }
        if(largest[0] == '0'){
            return "0";
        }
        return largest;
    }
};