/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>temp;
        int len = 0;
        while(head != NULL){
            len++;
            temp.push_back(head->val);
            head = head->next;
        }
        if(len<=3)return {-1,-1};
        vector<int>criticalpts;
        for(int i = 1;i< temp.size()-1;i++){
            if((temp[i] > temp[i-1] && temp[i] > temp[i+1]) || (temp[i] < temp[i-1] && temp[i] < temp[i+1]) ){
                criticalpts.push_back(i);
            } 
        }
        if(criticalpts.size() <= 1) return {-1,-1};

        int mini= INT_MAX;
        int maxi =abs( criticalpts[0] - criticalpts[criticalpts.size()-1]);
        for(int i=0;i<criticalpts.size()-1;i++){
             mini = min(mini,abs(criticalpts[i]-criticalpts[i+1]));
        }

        return {mini, maxi};
    }
};