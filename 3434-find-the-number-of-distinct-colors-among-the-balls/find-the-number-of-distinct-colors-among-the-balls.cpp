class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> m1;
        unordered_map<int, int> m2;
        vector<int> result(queries.size());
        int cnt = 0;

        for (int i = 0; i < queries.size(); i++) {
            int ball = queries[i][0];
            int newColor = queries[i][1];
            
            if (m1.find(ball) != m1.end()) {
                int oldColor = m1[ball];
                if (oldColor != newColor) {
                   
                    m2[oldColor]--;
                    if (m2[oldColor] == 0) {
                        cnt--;
                    }
                    m2[newColor]++;
                    if (m2[newColor] == 1) {
                        cnt++;
                    }
                    m1[ball] = newColor;
                }
            } else {
               
                m1[ball] = newColor;
                m2[newColor]++;
                if (m2[newColor] == 1) {
                    cnt++;
                }
            }
            result[i] = cnt;
        }

        return result;
    }
};