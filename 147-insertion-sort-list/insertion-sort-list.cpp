class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {

        /* 
        brute force approach 
        vector<int>v;
        ListNode*temp = head;
        while(temp){
            v.push_back(temp->val);
            temp = temp->next;
        }int j =0 ;
        for(int i =1 ;i<v.size();i++){
            int key = v[i];
            j = i -1;
            while(j>=0 && v[j]> key){
                v[j+1] = v[j];
                j--;
            }
            v[j+1]= key;
        }int i = 0;
        temp = head;
        while(temp){   
            temp ->val = v[i];
            temp = temp->next;
            i++;
        } 
        return head;
        */

        ListNode*dummy = new ListNode(-1);
        ListNode*prev = dummy , *curr= head;
        while(curr){
            ListNode*next = curr->next;
            while(prev->next && prev->next->val < curr->val) prev = prev->next;
            curr->next = prev->next;
            prev->next = curr;
            prev = dummy;
            curr = next;
        }
        return dummy->next;

    
    }
};