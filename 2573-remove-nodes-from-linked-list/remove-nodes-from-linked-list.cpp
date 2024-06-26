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
    ListNode* removeNodes(ListNode* head) {

ListNode* temp = head;
        vector<int>a;
        while(temp!= NULL){
            if(a.size() == 0) a.push_back(temp->val);
            else{
                while(a.size() && temp->val > a.back() ) a.pop_back();  
                a.push_back(temp->val); 
            }
            temp = temp->next;    
        }
        ListNode* root = new ListNode(a[0]);
        ListNode * t = root ;
        for(int i = 1 ;i< a.size();i++){
            t ->next = new ListNode(a[i]);
            t = t->next;
        }
return root;
    }
};