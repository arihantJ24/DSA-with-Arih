class Solution {
    private :
    vector <int> nextsmallestelement(vector<int> arr , int n){
        stack<int> st ;
        st.push(-1);
        vector <int> ans(n);

        for(int i = n-1 ;i>=0;i--){
            int curr = arr[i];
            while(st.top() != -1 && arr[st.top()] >= curr) {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

     vector <int> prevsmallestelement(vector<int> arr , int n){
        stack<int> st ;
        st.push(-1);
        vector <int> ans(n);

        for(int i = 0 ;i<n;i++){
            int curr = arr[i];
            while( st.top() != -1 && arr[st.top()] >= curr) {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }


    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> next(n);
        next =nextsmallestelement(heights , n);

        vector<int> prev(n);
        prev=prevsmallestelement(heights , n);
        int area = INT_MIN;

        for(int i =0;i< n;i++){
            int l = heights[i];

            if(next[i] == -1) next[i] = n;

            int b = next[i] - prev[i] -1 ;

            int newarea = l*b ;

            area = max (area, newarea);
        }


return area;

    }

public:

    int maximalRectangle(vector<vector<char>>& matrix) {

     vector<vector<int>> v(matrix.size());
       for(int i=0;i<matrix.size();i++){
           for(int j=0;j<matrix[i].size();j++){
               if(matrix[i][j]=='0')
  v[i].push_back(0);
  else v[i].push_back(1);
           }
       } 

        int area = largestRectangleArea(v[0]);
        for(int i = 1;i< v.size() ;i++){
            for(int j =0;j<v[i].size();j++){
                if(v[i][j] != 0){
                  v[i][j] = v[i][j] + v[i-1][j];
                    
                }
                else{
                    v[i][j] = 0;
                }
            }
            area = max(area,largestRectangleArea(v[i]) );

        }
        return area;
    }
};