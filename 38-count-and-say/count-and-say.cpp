class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        else{
            string prev = countAndSay(n - 1);
            string result = "";
            int count = 1;
            for (int i = 0; i < prev.length(); i++) {
                if (i == prev.length() - 1 || prev[i] != prev[i + 1]) {
                    result += to_string(count) + prev[i];
                    count = 1;
                } 
                else {
                    count++;
                }
            }
            return result;
        }
    }
};