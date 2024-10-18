 // TC: O(n)
  bool isPalindrome(ListNode* head) {
        ListNode*temp=head;
        vector<ListNode*>v;
        while(temp){
            v.push_back(temp);
            temp=temp->next;
        }
        int j=v.size()-1;
        for(int i=0;i<v.size()/2;i++){
            if(v[i]->val!=v[j]->val) return false;
            j--;
        }
        return true;
    }