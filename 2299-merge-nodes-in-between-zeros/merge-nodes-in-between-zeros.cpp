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
    ListNode* mergeNodes(ListNode* head) {
        // ListNode*curr = head->next;
        // ListNode*temp = curr;
        // int sum = 0;
        // while( temp!= NULL && temp->val != 0){
        //     sum+= temp->val;
        //     temp = temp->next;
        // }

        // curr->val = sum; 

        // curr->next = mergeNodes(temp);

        // return curr;

        ListNode*p1 = head->next;
        ListNode*p2 = p1;
        

        while(p2!=NULL){
            
            int sum = 0;
            while(p2!= NULL && p2->val != 0){
                sum+= p2->val;
                p2= p2->next;
            }
            p2 = p2->next;
            p1->val = sum;
            p1 ->next= p2 ;
            p1 = p1->next;
        }
        return head->next;
    }
};