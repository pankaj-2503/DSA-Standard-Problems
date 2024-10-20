class Solution {
public:
// TC -> O(N)
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next==NULL ) return NULL;
        if(head && head->next && head->next->next==NULL){
            head->next=NULL;
            return head;
        }
        ListNode*slow=head;
        ListNode*fast=head;
        ListNode*prev=NULL;
        while(fast && fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*temp=slow;
        prev->next=temp->next;
        temp->next=NULL;
        return head;

        
    }
};