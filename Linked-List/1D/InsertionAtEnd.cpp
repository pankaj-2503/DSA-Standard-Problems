 // TC:O(N)
 Node *insertAtEnd(Node *head, int x) {
        // Code here
        if(head==NULL) return new Node(x);
        
        Node*temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new Node(x);
        return head;
    }