class Solution {
public:
    int helper(ListNode*head, int k){
        ListNode*temp = head;
        while(head->next != head){
            ListNode*prev = NULL;
            for(int i = 1;i<k;i++){
                prev = temp;
                temp = temp->next;
            }
            if(temp == head) head = head->next;
            prev->next = temp->next;
            delete(temp);
            temp = prev->next;
        }
        return head->val;
    }
    int findTheWinner(int n, int k) {
        // ------------------------------M1 -> circular list---------------------
        if(k==1)return n;
        ListNode*head = NULL, *tail = NULL;
        for(int i = 1;i<=n;i++){
            ListNode* node = new ListNode(i);
            if(head== NULL) head= tail = node;
            else{
                tail->next = node;
                tail = node;
            }
            tail->next= head; // for circular list
        }
        return helper(head,k);

    }
};