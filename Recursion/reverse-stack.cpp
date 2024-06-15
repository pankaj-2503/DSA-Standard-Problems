 // Time complexitY - O(N*N) , space complexity - O(N)
 void insertAtBottom(stack<int>&St,int x){
        if(St.empty()){
            St.push(x);
        }
        else{
            int top=St.top();
            St.pop();
            insertAtBottom(St,x);
            St.push(top);
        }
        
    }
    void Reverse(stack<int> &St){
        if(St.empty()) return;
        int x=St.top();
        St.pop();
    
        Reverse(St);
        insertAtBottom(St,x);
        
        
    }