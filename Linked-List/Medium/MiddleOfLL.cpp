// TC - O(2N)
ListNode* middleNode(ListNode* head) {
        int cnt=0;
        ListNode*temp=head;
        while(temp){
            cnt++;
            temp=temp->next;
        }
        int mid=cnt/2;
        temp=head;
        while(mid--){
            temp=temp->next;
        }
        return temp;
}

// TC-O(n)

// using hare and tortoise method
ListNode* middleNode(ListNode* head) {
        ListNode*fast=head;
        ListNode*slow=head;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
}

