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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummynode = new ListNode(0);
        dummynode->next = head;
        ListNode* curr = dummynode;
        int samenode ;
        while(curr->next && curr->next->next){
            if(curr->next->val == curr->next->next->val){
                samenode= curr->next->val;
                while(curr->next && samenode == curr->next->val){
                    curr->next = curr->next->next;
                }
            }
            else{
                curr = curr->next;
            }
        }
        return dummynode->next;
    }
};