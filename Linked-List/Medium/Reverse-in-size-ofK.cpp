class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL) return NULL;

        ListNode*checker=head;
        for(int i=0;i<k;i++){
            if(checker==NULL) return head;
            checker=checker->next;
        }
        
        ListNode*prev=NULL;
        ListNode*cur=head;
        ListNode*next;
        int cnt=0;
        while(cnt<k && cur){
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
            cnt++;
        }
        if(next) head->next=reverseKGroup(next,k);
        return prev;
    }
};