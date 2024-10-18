 int len(Node*slow,Node*fast){
        int cur=1;
        fast=fast->next;
        while(fast!=slow){
            cur++;
            fast=fast->next;
        }
        return cur;
    }
    int countNodesinLoop(Node *head) {
        // Code here
        Node*slow=head;
        Node*fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                return len(slow,fast);
            }
        }
        
        return 0;
        
        
    }