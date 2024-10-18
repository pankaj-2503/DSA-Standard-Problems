// tC: O(N)
Node* constructLL(vector<int>& arr) {
        // code here
       if(arr.empty()) return NULL;
       Node*head=new Node(arr[0]);
       Node*curr=head;
       for(int i=1;i<arr.size();i++){
           curr->next=new Node(arr[i]);
           curr=curr->next;
       }
       return head;
    }