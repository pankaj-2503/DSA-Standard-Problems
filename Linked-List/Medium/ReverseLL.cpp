class Solution {
public:
// TC: O(N)
    ListNode* reverseList(ListNode* head) {
        ListNode*curr=head;
        ListNode*next;
        ListNode*prev=NULL;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
};

// REcursion
 ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode*newHead=reverseList(head->next);
        // just reverse starting 2 nodes rest is handled by recursion
        ListNode*front=head->next;
        front->next=head;
        head->next=NULL;
        return newHead;
    }