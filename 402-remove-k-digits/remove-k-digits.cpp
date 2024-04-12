class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st; 
        for(int i = 0 ; i< num.size() ; i++){
            while(!st.empty() && k>0 && num[i] < st.top()){
                k--;
                st.pop();
            }   

            st.push(num[i]);

            if(st.size() == 1 && num[i] == '0')
                st.pop();
        }
        while(k && !st.empty()){
            --k;
            st.pop();
        }
        string ans = "";
        while(!st.empty()){
            ans+= st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        if(ans == "")return "0";
        else return ans;
    }
};